#再入院率予測
#year by year(各年ごと)
#sample selection model

########################     暫定hekit    #####################
library(sampleSelection)

rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/rehos/h25.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

a <- selection(DPCdummy ~ general_beds +nurse # +doctor   
               + ave_serve_doctor#+ allowance_doctor 
               + use_rates_general 
               + ave_inpatient_per1day + ave_outpatient_per1day
               + medical_fee_per1inpatient
               + inspections_per100patients
               + areas_facility
               ,sai100 ~ #h25 + h24 + h23 + h22 #+ year          #再入院を予測
                 + nurse#+ general_beds #+doctor  
               + use_rates_general #+ ave_stays_general
               + medical_fee_per1outpatient#+ medical_fee_per1inpatient 
               + areas_facility
               ,data = data4, weights= NULL, method = "2step")   #data = udata
options(scipen=16)
summary(a)


start <- 13;
coefs <- a$coefficient[start:length(a$coefficient)-2]
sigma <- a$coefficient[length(a$coefficient)-1]  
a_var <- a$vcov[nrow = start:length(a$coefficient)-2 , ncol = start:length(a$coefficient)-2]

outdata <- data.frame(a_var, coefs, sigma)
write.csv(outdata, "rehos_h25result.csv", quote=FALSE, row.names=TRUE)


#各年逆行列,係数から漸近正規分布作成（H20から作る）
rm(list=ls())

data5 <- read.csv("/Users/serubantesu2/Downloads/hekit/rehos/vars/rehos_h25result.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#head(data5)
coef_vector <- as.vector(data5[1:length(data5$X),length(data5$X)+2])
V_matrix <- as.matrix(data5[1:length(data5$X),1:length(data5$X)+1])


h20V_inv <- solve(V_matrix)
h20_coefs <- coef_vector

h21V_inv <- solve(V_matrix)
h21_coefs <- coef_vector

h22V_inv <- solve(V_matrix)
h22_coefs <- coef_vector

h23V_inv <- solve(V_matrix)
h23_coefs <- coef_vector

h24V_inv <- solve(V_matrix)
h24_coefs <- coef_vector

h25V_inv <- solve(V_matrix)
h25_coefs <- coef_vector

v <- var_cov   #各年重み付け係数
w_h20 <- v %*% h20V_inv %*% h20_coefs
w_h21 <- v %*% h21V_inv %*% h21_coefs 
w_h22 <- v %*% h22V_inv %*% h22_coefs 
w_h23 <- v %*% h23V_inv %*% h23_coefs 
w_h24 <- v %*% h24V_inv %*% h24_coefs
w_h25 <- v %*% h25V_inv %*% h25_coefs

#係数統合,と係数の分散共分散行列
total_weight <- h20V_inv + h21V_inv + h22V_inv + h23V_inv + h24V_inv + h25V_inv  #ここでは係数の分散共分散行列
numerator <-  h20V_inv %*% h20_coefs + h21V_inv %*% h21_coefs +
  + h22V_inv %*% h22_coefs + h23V_inv %*% h23_coefs +
  + h24V_inv %*% h24_coefs + h25V_inv %*% h25_coefs
integrated_coefs <- solve(total_weight) %*% numerator
var_cov <- solve(total_weight)

metaana_out <- data.frame(var_cov, integrated_coefs,w_h20,w_h21,w_h22,w_h23,w_h24,w_h25)
write.csv(metaana_out, "metaana_coefs_rehos.csv", quote=FALSE, row.names=TRUE)



#/* *******************暫定pooled OLS*********************** */

library(plm)

rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/h18-h25panel_exist.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

rehos_pred <- plm(sai100 ~ #h25 + h24 + h23 + h22 #+ year          #再入院を予測
                  + use_rates_general #+ ave_stays_general
                  + ave_outpatient_per1day + ave_inpatient_per1day   
                  + medical_fee_per1outpatient + medical_fee_per1inpatient 
                  , data=data4, model="pooling") 
options(scipen=16)
summary(rehos_pred)

e <- rehos_pred$residual
n <- length(rehos_pred$residual)
k <- length(rehos_pred$coefficient)
sigma <- sqrt( ( 1 / (n - k) ) * e %*% e )
#AIC <- log(sigma^2) + 2*k/n

coefs <- rehos_pred$coefficient
a_var <- rehos_pred$vcov

outdata <- data.frame(a_var, coefs, sigma)
write.csv(outdata, "pred_rehos.csv", quote=FALSE, row.names=TRUE)


# 動作しない  
?plm
step(rehos_pred)

library(MuMIn)
#options(na.action = "na.fail")

dredge(rehos_pred,rank="AIC")
best.model <- get.models(dredge(rehos_pred,rank="AIC"), subset = 1)[1]


#/* *******************変数考察用やーつ*********************** */
rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/rehos/h20.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

#エラーなしversion
DPCprobit <- glm(DPCdummy ~ general_beds +nurse # +doctor   
                 #+ h25 + h24 + h23 + h22 # + year
                 + ave_serve_doctor+ allowance_doctor 
                 + use_rates_general #+ ave_stays_general
                 + ave_inpatient_per1day + ave_outpatient_per1day
                 + medical_fee_per1inpatient #+ medical_fee_per1outpatient
                 + inspections_per100patients
                 #+ fixed_assets_per1bed
                 + non_medical_revenue+ medical_revenue  
                 #+ medical_cost_per1day1man
                 + areas_facility
                 ,family = binomial( link = "probit"), data=data4)
#summary(DPCprobit)


a <- selection(DPCdummy ~ general_beds +nurse # +doctor   
               #+ h25 + h24 + h23 + h22 # + year
               + ave_serve_doctor#+ allowance_doctor 
               + use_rates_general #+ ave_stays_general
               + ave_inpatient_per1day + ave_outpatient_per1day
               + medical_fee_per1inpatient #+ medical_fee_per1outpatient
               + inspections_per100patients
               #+ fixed_assets_per1bed
               #+ non_medical_revenue#+ medical_revenue  
               #+ medical_cost_per1day1man
               + areas_facility
               ,sai100 ~ #h25 + h24 + h23 + h22 #+ year          #再入院を予測
                 + nurse#+ general_beds #+doctor  
               #+ ave_serve_doctor#+ allowance_doctor 
               + use_rates_general #+ ave_stays_general
               #+ ave_inpatient_per1day #+ ave_outpatient_per1day  
               + medical_fee_per1outpatient#+ medical_fee_per1inpatient 
               #+ inspections_per100patients
               #+ fixed_assets_per1bed
               #+ medical_revenue + non_medical_revenue
               #+ medical_cost_per1day1man
               + areas_facility
               ,data = data4, weights= NULL, method = "2step")   #data = udata
options(scipen=16)
summary(a)


#/* *******************pooled OLS 変数考察用やーつ*********************** */

rehos_pred <- plm(sai100 ~ #h25 + h24 + h23 + h22 #+ year          #再入院を予測
                    #+ nurse+ general_beds #+doctor  
                    #+ ave_serve_doctor #+ allowance_doctor 
                    + use_rates_general #+ ave_stays_general
                  + ave_outpatient_per1day + ave_inpatient_per1day   
                  + medical_fee_per1outpatient + medical_fee_per1inpatient 
                  #+ inspections_per100patients
                  #+ fixed_assets_per1bed
                  #+ medical_revenue + non_medical_revenue
                  #+ medical_cost_per1day1man
                  #+ areas_facility
                  , data=data4, model="pooling") 
summary(rehos_pred)
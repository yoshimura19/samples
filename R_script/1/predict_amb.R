#救急車搬送数予測
#year by year(各年ごと)
#sample selection model

########################     暫定hekit    #####################
library(sampleSelection)

rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/kyu/h25.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

a <- selection(DPCdummy ~ general_beds +nurse # +doctor   
               + ave_serve_doctor#+ allowance_doctor 
               + use_rates_general #+ ave_stays_general
               + ave_inpatient_per1day + ave_outpatient_per1day
               + medical_fee_per1inpatient #+ medical_fee_per1outpatient
               + inspections_per100patients
               + areas_facility
               ,ambulance_1month ~ + nurse#+ general_beds #+  +doctor  
               + ave_inpatient_per1day + ave_outpatient_per1day
               + medical_fee_per1inpatient #+ medical_fee_per1outpatient
               + areas_facility
               ,data = data4, weights= NULL, method = "2step")   #data = udata
summary(a)
a$vcov
a$coefficient


#2段階目の係数と分散共分散行列出力
start <- 13;
coefs <- a$coefficient[start:length(a$coefficient)-2]
sigma <- a$coefficient[length(a$coefficient)-1]  
a_var <- a$vcov[nrow = start:length(a$coefficient)-2 , ncol = start:length(a$coefficient)-2]

solve(a_var)
outdata <- data.frame(a_var, coefs, sigma)
write.csv(outdata, "h24result.csv", quote=FALSE, row.names=TRUE)



#各年逆行列,係数から漸近正規分布作成（H20から作る）
rm(list=ls())
data5 <- read.csv("/Users/serubantesu2/Downloads/hekit/kyu/vars/h25result.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
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
write.csv(metaana_out, "metaana_coefs.csv", quote=FALSE, row.names=TRUE)


#H20外したver(初期化0代入)
total_weight <- h21V_inv + h22V_inv + h23V_inv + h24V_inv + h25V_inv  #ここでは係数の分散共分散行列
numerator <- h21V_inv %*% h21_coefs +
  + h22V_inv %*% h22_coefs + h23V_inv %*% h23_coefs +
  + h24V_inv %*% h24_coefs + h25V_inv %*% h25_coefs
integrated_coefs <- solve(total_weight) %*% numerator
var_cov <- solve(total_weight)



# /* ********************** ミルズ比作成 ************************ */ 

rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/mroz/h25.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

#probit用データ
edata <- model.frame(DPCdummy ~ id + general_beds + nurse 
                     + ave_serve_doctor + use_rates_general 
                     + ave_inpatient_per1day + ave_outpatient_per1day
                     + medical_fee_per1inpatient + inspections_per100patients + areas_facility
                     ,data=data4)

#暫定使用version(ミルズ比作成)
DPCprobit <- glm(DPCdummy ~ general_beds +nurse 
                 + ave_serve_doctor + use_rates_general 
                 + ave_inpatient_per1day + ave_outpatient_per1day
                 + medical_fee_per1inpatient + inspections_per100patients + areas_facility
                 ,family = binomial( link = "probit"), data=edata)
#summary(DPCprobit)

MrozDPC <- invMillsRatio(DPCprobit)$IMR1

Mroz_data <- data.frame(edata$id, MrozDPC)
write.csv(Mroz_data, "Mroz_h25.csv", quote=FALSE, row.names=FALSE)  #yearで名前書き換え
#ここで救急車搬送数データを統合の必要(idでvlookup)



library(MASS)#代入式の作成

#説明変数行列の作成
g <- udata         #欠損しているデータ
x <- as.matrix(data.frame(g$h25,g$h24,g$h23,g$h22,g$general_beds
                          ,g$use_rates_general,g$ave_inpatient_per1day
                          ,g$medical_fee_per1inpatient,g$medical_fee_per1outpatient
                          ,g$inspections_per100patients,g$fixed_assets_per1bed
                          ,g$MrozDPC            #invMillsRatio
))     #推定した係数順になっていることを確認
x <- cbind( rep(1,length(g$h25)) ,x)
head(x)
x[1,]

rm(predicted_amb)   #初期化
predicted_amb <- matrix(rep(0,length(g$h25)*giji_n), nrow=length(g$h25),ncol=giji_n)
head(predicted_amb)




#/* *******************変数考察用やーつ*********************** */

data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/h24.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

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
               ,ambulance_1month ~ #h25 + h24 + h23 + h22 #+ year 
                 + nurse#+ general_beds #+  +doctor  
               #+ ave_serve_doctor#+ allowance_doctor 
               #+ use_rates_general #+ ave_stays_general
               + ave_inpatient_per1day #+ ave_outpatient_per1day  
               + medical_fee_per1inpatient + medical_fee_per1outpatient
               #+ inspections_per100patients
               #+ fixed_assets_per1bed
               #+ medical_revenue + non_medical_revenue
               #+ medical_cost_per1day1man
               + areas_facility
               ,data = data4, weights= NULL, method = "2step")   #data = udata
options(scipen=16)
summary(a)




#/* ******************* DPC参入要因調べ *********************** */# 

rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/panel_logit/cross/cross/h22.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

#before
rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/panel_logit/before3/h21.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

DPClogit <- glm(DPCdummy ~ ruisekiDPC + general_beds +doctor #+nurse    
                 #+ h25 + h24 + h23 + h22 # + year
                 + ave_serve_doctor 
                 + use_rates_general 
                 + ave_inpatient_per1day + ave_outpatient_per1day
                 + non_medical_revenue   
                 #+ areas_facility    ←チェック中
                + ave_stays_general 
                #+ fixed_assets_per1bed + medical_cost_per1day1man
                #+ medical_revenue + medical_fee_per1outpatient
                #+ allowance_doctor + medical_fee_per1inpatient 
                + inspections_per100patients
                 ,family = binomial( link = "logit"), data=data4)
options(scipen=16)
summary(DPClogit)


#raw
#H18 26 || H20 66 || H21 129 || H22 23 || H23 10 || H24 13

#before 2年後decisionをした
# H18 66 || H19 129 |||| H20 23 || H21 10 || H22 10
# 2008年 h20 から準備病院(h22加入)

#full model
DPClogit <- glm(DPCdummy ~ ruisekiDPC + general_beds +doctor #+nurse    
                #+ h25 + h24 + h23 + h22 # + year
                + ave_serve_doctor+ allowance_doctor 
                + use_rates_general 
                + ave_inpatient_per1day + ave_outpatient_per1day
                + medical_fee_per1inpatient #+ medical_fee_per1outpatient
                + inspections_per100patients
                + non_medical_revenue #+ medical_revenue       #多重共線性  
                #+ medical_cost_per1day1man
                + areas_facility
                + ave_stays_general #+ fixed_assets_per1bed
                ,family = binomial( link = "logit"), data=data4)
summary(DPClogit)

g <- data4
check_cor <- data.frame(g$ruisekiDPC,g$general_beds,g$doctor, #+nurse    
                        g$ave_serve_doctor,g$use_rates_general,
                        g$ave_inpatient_per1day,g$ave_outpatient_per1day,
                        g$medical_fee_per1inpatient,g$inspections_per100patients,
                        g$non_medical_revenue,
                        #g$medical_revenue,g$medical_cost_per1day1man
                        g$areas_facility,g$ave_stays_general)
cor(check_cor, use = "pairwise.complete.obs")
cor(data4$areas_facility,data4$general_beds, use = "pairwise.complete.obs")



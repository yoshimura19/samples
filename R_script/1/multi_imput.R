a <- selection(pre_DPC ~ doctor + nurse + general_beds
               + year
               #+ allowance_doctor + ave_serve_doctor
               #+ use_rates_general #+ ave_stays_general
               #+ ave_inpatient_per1day + ave_outpatient_per1day
               #+ medical_fee_per1inpatient + medical_fee_per1outpatient
               #+ inspections_per100patients
               #+ fixed_assets_per1bed
               + medical_revenue + non_medical_revenue
               #+ medical_cost_per1day1man
               #+ areas_facility
               ,ambulance_1month ~  
               + nurse + year #+ doctor 
               #+ allowance_doctor #+ ave_serve_doctor
               #+ use_rates_general #+ ave_stays_general
               #+ ave_inpatient_per1day + ave_outpatient_per1day
               #+ medical_fee_per1inpatient + medical_fee_per1outpatient
               #+ inspections_per100patients
               #+ fixed_assets_per1bed
               + medical_revenue + non_medical_revenue
               #+ medical_cost_per1day1man
               #+ areas_facility
               ,data = udata, weights= NULL, method = "2step")
summary(a)
options(scipen=10)
a$coefficients
a$vcov


########################     暫定hekit    #####################
a <- selection(DPCdummy ~ doctor + nurse + general_beds
               + h25 + h24 + h23 + h22 # + year
               + ave_serve_doctor#+ allowance_doctor 
               + use_rates_general #+ ave_stays_general
               + ave_inpatient_per1day + ave_outpatient_per1day
               + medical_fee_per1inpatient + medical_fee_per1outpatient
               + inspections_per100patients
               + fixed_assets_per1bed
               #+ non_medical_revenue#+ medical_revenue 
               #+ medical_cost_per1day1man
               #+ areas_facility
               ,ambulance_1month ~ h25 + h24 + h23 + h22 #+ year 
               + general_beds #+ nurse #+doctor  
               #+ ave_serve_doctor#+ allowance_doctor 
               + use_rates_general #+ ave_stays_general
               + ave_inpatient_per1day #+ ave_outpatient_per1day  
               + medical_fee_per1inpatient + medical_fee_per1outpatient
               + inspections_per100patients
               + fixed_assets_per1bed
               #+ medical_revenue + non_medical_revenue
               #+ medical_cost_per1day1man
               #+ areas_facility
               ,data = udata, weights= NULL, method = "2step")
options(scipen=10)
summary(a)
a$vcov
a$coefficient

write.csv(a$coefficient, "hekit_coefs.csv", quote=TRUE, row.names=TRUE)
write.csv(a$vcov, "hekit_vars.csv", quote=FALSE, row.names=TRUE)


library(MASS)#代入式の作成
#パラメタ
giji_n <- 3  #疑似データセット数
start <- 19;
beta <- a$coefficient[start:length(a$coefficient)-2]
a_var <- a$vcov[nrow = start:length(a$coefficient)-2 , ncol = start:length(a$coefficient)-2]
sigma_hat2 <- (a$coefficient[length(a$coefficient)-1])^2
#hist(rnorm(1000,mean=0,sd=sigma_hat))
?rchisq()

k <- 13 #hekitの推定係数数
mk <- 1346 #データが全て得られているiの数
chi_df <- mk - k

g_b <- generated_beta <- mvrnorm(giji_n, beta, a_var)   #係数の乱数
generated_s <- ( sigma_hat2 * rchisq(giji_n , df = chi_df) / chi_df )^(1/2)
g_e <- giji_error <- generated_s * runif(giji_n, min=0, max=1)


#補完値の作成
g <- udata         #欠損しているデータ
x <- as.matrix(data.frame(g$h25,g$h24,g$h23,g$h22,g$general_beds
                          ,g$use_rates_general,g$ave_inpatient_per1day
                          ,g$medical_fee_per1inpatient,g$medical_fee_per1outpatient
                          ,g$inspections_per100patients,g$fixed_assets_per1bed
                          ,g$MrozDPC            #invMillsRatio
                          ))     #推定した係数順になっていることを確認
x <- cbind( rep(1,length(g$h25)) ,x)
head(x)
predicted_amb <- x %*% g_b[1,] + g_e[1]
#summary(predicted_amb)


x1 <- cbind(x, g$ambulance_1month)
x2 <- cbind(x , predicted_amb)
rbind(x1,x2)          #補完データと結合

#plm(モデル式, model=“within”, effect=“twoways”)

library(plm)
is.data.frame(udata)
public_panel_fixed <- plm(medical_cost_per1day1man  ~ general_beds 
                          + use_rates_general
                          + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day
                          + fixed_assets_per1bed + doctor + nurse
                          , data=data4, model="random") 
summary(public_panel_fixed)
head(udata)

panel.FEmodel <- plm(general_beds ~ use_rates_general#inspections_per100patients + fixed_assets_per1bed
                     ,data = udata, model = "within")
summary(panel.FEmodel)




#step by step
#sample selection model
rm(list=ls())

library(sampleSelection)
data4 <- read.csv("/Users/serubantesu2/Downloads/h25-21panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#attach(data4)
#data4
#ls(data4)

#probit用データ
edata <- model.frame(total_id ~ id + year + DPCdummy + pre_DPC + doctor + nurse
                     +h25 + h24 + h23 + h22 + h21#+ year
                     + general_beds
                     + allowance_doctor + ave_serve_doctor
                     + use_rates_general + ave_stays_general
                     + ave_inpatient_per1day + ave_outpatient_per1day
                     + inpatients_per1doctor + outpatients_per1nurse
                     + medical_fee_per1inpatient + medical_fee_per1outpatient
                     + inspections_per100patients
                     + fixed_assets_per1bed
                     + medical_revenue + non_medical_revenue
                     + medical_cost_per1day1man
                     + areas_facility
                     #+ kubun + ken + shi + name
                     ,data=data4)
#length(edata$DPCdummy)
#attach(edata)

DPCprobit <- glm(DPCdummy 
                 ~  nurse + general_beds + doctor
                 + h25 + h24 + h23 + h22 #+ h21 #+ year
                 + allowance_doctor + ave_serve_doctor
                 + use_rates_general #+ ave_stays_general
                 + ave_inpatient_per1day + ave_outpatient_per1day
                 + medical_fee_per1inpatient + medical_fee_per1outpatient
                 + inspections_per100patients
                 + fixed_assets_per1bed
                 + non_medical_revenue + medical_revenue 
                 #+ medical_cost_per1day1man
                 + areas_facility
                 #+ outpatients_per1nurse#+ inpatients_per1doctor #
                  ,family = binomial( link = "probit"), data=edata)
summary(DPCprobit)
dpcpro <- step(DPCprobit)

#trimming検討
ps <- DPCprobit$fitted
checkdata <- data.frame(edata,ps)
write.csv(checkdata, "checkdata.csv", quote=FALSE, row.names=FALSE)


MrozDPC <- invMillsRatio(DPCprobit)$IMR1


#Mroz0DPC <- invMillsRatio(DPCprobit)$IMR0
#cor(MrozDPC,Mroz0DPC)

udata <- data.frame(edata, MrozDPC)
write.csv(udata, "udata.csv", quote=FALSE, row.names=FALSE)
#ここで救急車搬送数データを統合の必要(total_idでvlookup)


rm(list=ls())
udata <- read.csv("/Users/serubantesu2/Downloads/udata.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

temp <- subset(udata, subset= pre_DPC == 1)
imp <- subset(udata, subset= pre_DPC == 0)

write.csv(temp, "temp.csv", quote=FALSE, row.names=FALSE)
write.csv(imp, "imp.csv", quote=FALSE, row.names=FALSE)
#ここでsubsetのデータの作り方失敗箇所を確認

rm(list=ls())
datatemp <- read.csv("/Users/serubantesu2/Downloads/temp2.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
dataimp <- read.csv("/Users/serubantesu2/Downloads/imp2.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932")
#attach(datatemp)
#attach(dataimp)

#plot(datatemp$MrozDPC)
#hist(datatemp$MrozDPC)
#summary(dataimp$MrozDPC)

HekitDPC <- lm(ambulance_1month ~  
               #+ general_beds
               + nurse + year #+ doctor 
               + allowance_doctor #+ ave_serve_doctor
               + use_rates_general #+ ave_stays_general
               + ave_outpatient_per1day + ave_inpatient_per1day 
               + medical_fee_per1inpatient + medical_fee_per1outpatient
               #+ inspections_per100patients
               #+ fixed_assets_per1bed
               + medical_revenue + non_medical_revenue
               #+ medical_cost_per1day1man
               #+ areas_facility
               + MrozDPC
                , data = datatemp)  #
options(scipen=10)
summary(HekitDPC)

x1 <- predict(HekitDPC, datatemp)
x2 <- predict(HekitDPC, dataimp)
write(x2, file="x2.txt")
write.csv(x2, "x2.csv", quote=FALSE, row.names=FALSE)
length(x2)

x <- read.csv("x1.txt")
x
summary(x1)
sd(x1)
hist(x1)
summary(x2)
sd(x2)
hist(x2)
x2 <- subset(x2, x2 > -500)




data4 <- read.csv("/Users/serubantesu2/Downloads/246panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data4)

public_panel_fixed <- plm(ambulance_month ~ assets_building_100beds + outpatient_rate + doctors_100beds # + general_beds
                          + nurses_100beds + ave_impatient_per1day
                          , data=data4, model="pooling") 
summary(public_panel_fixed)

OLS <- lm( ambulance_month ~  outpatient_rate + doctors_100beds # + general_beds
           + nurses_100beds + ave_impatient_per1day, data = data4)
summary(OLS)



#GMM
library(gmm)
#estimating the parameters of a normal distribution
g1 <- function(tet,x){       #モーメントコンディション
  m1 <- (tet[1]-x)
  m2 <- (tet[2]^2 - (x - tet[1])^2)
  m3 <- x^3 - tet[1]*(tet[1]^2+3*tet[2]^2)
  f <- cbind(m1,m2,m3)
  return(f)
}

Dg <- function(tet,x){       #Gradient
  G <- matrix(c(1,
                2*(-tet[1]+mean(x)),
                -3*tet[1]^2-3*tet[2]^2,
                0,
                2*tet[2],
                -6*tet[1]*tet[2]),
                nrow=3,ncol=2)
  return(G)
}

set.seed(123)
n <- 200
x1 <- rnorm(n, mean = 4, sd = 2)

res <- gmm(g = g1,x = x1,t0 = c(mu=0,sig=0), grad = Dg)  
summary(res)

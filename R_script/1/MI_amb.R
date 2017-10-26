#step by step
#sample selection model
rm(list=ls())

library(sampleSelection)
data4 <- read.csv("/Users/serubantesu2/Downloads/h25-21panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#attach(data4)
#data4
#ls(data4)
check_cor <- data.frame(doctor,nurse,general_beds)
cor(check_cor, use="complete.obs")



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


DPCprobit <- glm(DPCdummy ~ doctor + nurse + general_beds
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
                 ,family = binomial( link = "probit"), data=udata)
summary(DPCprobit)

MrozDPC <- invMillsRatio(DPCprobit)$IMR1

udata <- data.frame(edata, MrozDPC)
write.csv(udata, "udata.csv", quote=FALSE, row.names=FALSE)
#ここで救急車搬送数データを統合の必要(total_idでvlookup)

rm(list=ls())
udata <- read.csv("/Users/serubantesu2/Downloads/udata2.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

temp <- subset(udata, subset= pre_DPC == 1)
imp <- subset(udata, subset= pre_DPC == 0)

write.csv(temp, "temp.csv", quote=FALSE, row.names=FALSE)
write.csv(imp, "imp.csv", quote=FALSE, row.names=FALSE)
#ここでsubsetのデータの作り方失敗箇所を確認

rm(list=ls())
datatemp <- read.csv("/Users/serubantesu2/Downloads/temp3.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
dataimp <- read.csv("/Users/serubantesu2/Downloads/imp2.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932")
#attach(datatemp)
#attach(dataimp)

HekitDPC <- lm(ambulance_1month ~ h25 + h24 + h23 + h22 #+ year 
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
               + MrozDPC
               , data = datatemp)  
options(scipen=10)
summary(HekitDPC)


x1 <- predict(HekitDPC, datatemp)
x2 <- predict(HekitDPC, dataimp)
#write(x2, file="x2.txt")
write.csv(x2, "x2.csv", quote=FALSE, row.names=FALSE)
length(x2)

x <- read.csv("x1.txt")
x2
summary(x1) : summary(x2)
sd(x1) ; sd(x2)
hist(x1)
hist(x2)
x2 <- subset(x2, x2 > -500) #兵庫災害医療(医師1人 h21;2人) udata2に反映
x2min <- subset(x2, x2 < -300)
x2min


########################     暫定hekit    #####################
rm(list=ls())
udata <- read.csv("/Users/serubantesu2/Downloads/udata2.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

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



#パラメタ
giji_n <- 10  #疑似データセット数

hokan_n <- length(g$h25)
start <- 19;
beta <- a$coefficient[start:length(a$coefficient)-2]
a_var <- a$vcov[nrow = start:length(a$coefficient)-2 , ncol = start:length(a$coefficient)-2]
sigma_hat2 <- (a$coefficient[length(a$coefficient)-1])^2
#hist(rnorm(1000,mean=0,sd=sigma_hat))

k <- 13 #hekitの推定係数数
mk <- 1346 #データが全て得られているiの数
chi_df <- mk - k



j <- 1    #初期疑似セット
for(j in 1:giji_n){

  #1データ目の係数列作成
  g_b <- generated_beta <- mvrnorm(hokan_n, beta, a_var)   #係数の乱数
  generated_s <- ( sigma_hat2 * rchisq(hokan_n , df = chi_df) / chi_df )^(1/2)
  g_e <- giji_error <- generated_s * runif(hokan_n, min=0, max=1)  #random_uniform
  head(g_b)

  #補完値の作成
  for(i in 1:hokan_n){    #giji_n
    predicted_amb[i,j] <- x[i,] %*% g_b[i,] + g_e[i]
  }

}
summary(predicted_amb)
head(predicted_amb)


imputed_data <- data.frame(udata, predicted_amb)
write.csv(imputed_data, "imputed_data3.csv", quote=FALSE, row.names=FALSE)


#データ毎に１つの式で埋める場合
for(i in 1:giji_n){    #giji_n
  predicted_amb[,i] <- x %*% g_b[i,] + g_e[i]    #それぞれの列を１つの係数行列
}


#残差は毎回更新，係数は疑似セット毎  ←これが正しい
j <- 1    #初期疑似セット
for(j in 1:giji_n){
  
  #係数列作成 (stochastic regression imputation)
  g_b <- generated_beta <- mvrnorm(1, beta, a_var)   #係数の乱数
  generated_s <- ( sigma_hat2 * rchisq(hokan_n , df = chi_df) / chi_df )^(1/2)
  g_e <- giji_error <- generated_s * runif(hokan_n, min=0, max=1) #誤差項はサンプルごとに
  
  #補完値の作成
  for(i in 1:hokan_n){    #giji_n
    predicted_amb[i,j] <- x[i,] %*% g_b + g_e[i]
  }
  
}
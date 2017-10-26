#year by year(各年ごと)
#sample selection model
rm(list=ls())


library(sampleSelection)
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/h19.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#attach(data4)
#data4
#ls(data4)
check_cor <- data.frame(doctor,nurse,general_beds)
cor(check_cor, use="complete.obs")



#probit用データ
edata <- model.frame(id ~ year + DPCdummy + doctor + nurse     #+ pre_DPC 
                     #+h25 + h24 + h23 + h22 + h21#+ year
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
                 #+ h25 + h24 + h23 + h22 # + year
                 + ave_serve_doctor#+ allowance_doctor 
                 + use_rates_general #+ ave_stays_general
                 + ave_inpatient_per1day + ave_outpatient_per1day
                 + medical_fee_per1inpatient + medical_fee_per1outpatient
                 + inspections_per100patients
                 + fixed_assets_per1bed
                 #+ non_medical_revenue#+ medical_revenue 
                 #+ medical_cost_per1day1man
                 #+ areas_facility
                 ,family = binomial( link = "probit"), data=edata)
summary(DPCprobit)

MrozDPC <- invMillsRatio(DPCprobit)$IMR1

udata <- data.frame(edata, MrozDPC)
write.csv(udata, "h25udata.csv", quote=FALSE, row.names=FALSE)  #yearで名前書き換え
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
library(sampleSelection)

rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/h22.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

a <- selection(DPCdummy ~ general_beds +nurse # +doctor   
               #+ h25 + h24 + h23 + h22 # + year
               + ave_serve_doctor#+ allowance_doctor 
               + use_rates_general #+ ave_stays_general
               + ave_inpatient_per1day + ave_outpatient_per1day
               + medical_fee_per1inpatient #+ medical_fee_per1outpatient
               + inspections_per100patients
               + areas_facility
               ,ambulance_1month ~ + nurse#+ general_beds #+  +doctor  
               + ave_inpatient_per1day 
               + medical_fee_per1inpatient + medical_fee_per1outpatient
               + areas_facility
               ,data = data4, weights= NULL, method = "2step")   #data = udata
options(scipen=16)
summary(a)
a$vcov
a$coefficient

#2段階目の係数と分散共分散行列出力
start <- 15;
coefs <- a$coefficient[start:length(a$coefficient)-2]
sigma <- a$coefficient[length(a$coefficient)-1]  
a_var <- a$vcov[nrow = start:length(a$coefficient)-2 , ncol = start:length(a$coefficient)-2]

solve(a_var)
outdata <- data.frame(a_var, coefs)
write.csv(outdata, "h19result.csv", quote=FALSE, row.names=TRUE)

#各年逆行列作成（H20から作る）
data5 <- read.csv("/Users/serubantesu2/Downloads/hekit/vars/h19result.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
head(data5)

V_matrix <- as.matrix(data5[1:length(data5$X),1:length(data5$X)+1])
h20V_inv <- solve(V_matrix)
h21V_inv <- solve(V_matrix)
h22V_inv <- solve(V_matrix)
h23V_inv <- solve(V_matrix)
h24V_inv <- solve(V_matrix)
h25V_inv <- solve(V_matrix)


#暫定使用version(ミルズ比作成)
DPCprobit <- glm(DPCdummy ~ general_beds +nurse 
                 + ave_serve_doctor + use_rates_general 
                 + ave_inpatient_per1day + ave_outpatient_per1day
                 + medical_fee_per1inpatient + inspections_per100patients + areas_facility
                 ,family = binomial( link = "probit"), data=data4)

MrozDPC <- invMillsRatio(DPCprobit)$IMR1



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


rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/merge/h18-h25panel_merged.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
summary(data4)
attach(data4)
ls(data4)
summary(doctor)
length(doctor)

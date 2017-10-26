#DID
rm(list=ls())


data10 <- read.csv("/Users/serubantesu2/Downloads/denryoku_panel_11-13.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data10)
data10
ls(data10)


X2012jishin <- data10$jishin*data10$X2012
X13tokyo <- data10$tokyo*data10$X13

DID <- lm(operating_revenue ~ X13 + tokyo + X13tokyo +
          + labor + internal_combustion_power + nuclear_power
          + new_energy_power + steam_power + Thermal_power
          ,data = data10)
options(scipen=10)
summary(DID)


data10 <- read.csv("/Users/serubantesu2/Downloads/717public_panel_DID_2period.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data10)
data10
ls(data10)

data11 <- read.csv("/Users/serubantesu2/Downloads/717public_panel_DID_3period.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data11)
data11
ls(data11)



h21_h22DPC <- (1-H21DPC)*H22DPC
h21h22DPCh22dummy <- (1-H21DPC)*H22DPC*H22Dummy
cor(H22DPC, h21h22DPC)
h21h22DPC

sum(h21h22DPC)
sum(h21h22DPCh22dummy)
sum(H22DPC*H22Dummy)


h21h22h23DPCh23dummy <- (1-H21DPC)*(1-H22DPC)*H23DPC*H23Dummy
sum(h21h22h23DPCh23dummy)


rm(OLS)
OLS <- lm(med_cost_per1man1day ~ H22Dummy + H22DPC 
          + h21h22DPCh22dummy                  #(1-H21DPC)*H22DPC*H22Dummy 
          + H21DPC
          + general_beds + use_rate_general_beds                            #↓共変量
          + ave_stay_general + ave_inpatient_per1day + outpatient_rate
          + doctors_100beds + pharmacist_100beds #+ assets_building_100beds 
          + nurses_100beds,data = data10)

DID <- lm(med_cost_per1man1day ~
            H23Dummy + H22Dummy + H23DPC + H22DPC + #H23Dummy*H23DPC + H22Dummy*H22DPC 
          + h21h22h23DPCh23dummy
          + H21DPC
          + general_beds + use_rate_general_beds                            #↓共変量
          + ave_stay_general + ave_inpatient_per1day #+ outpatient_rate
          + doctors_100beds + pharmacist_100beds + #assets_building_100beds 
          + nurses_100beds
      ,data = data11)

DID <- lm(ave_inpatient_per1day ~
            H23Dummy + H22Dummy + H23DPC + H22DPC + #H23Dummy*H23DPC + H22Dummy*H22DPC 
            + h21h22h23DPCh23dummy
          +h21h22DPCh22dummy
          + H21DPC
          + general_beds + use_rate_general_beds                            #↓共変量
          + ave_stay_general + #ave_inpatient_per1day #+ outpatient_rate
          + doctors_100beds + pharmacist_100beds #+ assets_building_100beds 
            + nurses_100beds
          ,data = data11)


 
#************* DPC加入で入院患者が増えたか ************#

rm(list=ls())
data12 <- read.csv("/Users/serubantesu2/Downloads/panel_logit/DID/DID20_22.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#attach(data11)
ls(data12)

DID <- lm(ave_inpatient_per1day ~ 
            H22DPC + H22dummy + H22DPC*H22dummy
          + general_beds + use_rates_general + nurse + ave_stays_general
          + ave_outpatient_per1day
          + non_medical_revenue
          + ave_old_doctor
          ,data = data12)
summary(DID)

options(scipen=10)
summary(OLS)
summary(DID)

cor(H22Dummy*H22DPC,H23Dummy*H23DPC)


public_panel_fixed <- plm(med_cost_per1man1day ~ general_beds + use_rate_general_beds
                          + ave_stay_general + ave_impatient_per1day + outpatient_rate
                          + assets_building_100beds + doctors_100beds + pharmacist_100beds
                          + nurses_100beds
                          , data=data4, model="within") 



data4 <- read.csv("/Users/serubantesu2/Downloads/675-246panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data4)
data4
ls(data4)

library(plm)

public_panel_fixed <- plm(ambulance_month ~ general_beds + use_rate_general_beds
                          + ave_stay_general + ave_impatient_per1day + outpatient_rate
                          + assets_building_100beds + doctors_100beds + pharmacist_100beds
                          + nurses_100beds
                          , data=data4, model="within") 
options(scipen=10)
public_panel_random
public_panel_fixed
summary(public_panel_random)
summary(public_panel_fixed)
summary(fixef(public_panel_fixed))

general_beds

#C,GENERAL_BEDS,USE_RATE_GENERAL_BEDS,AVE_STAY_GENERAL,AVE_IMPATIENT_PER1DAY,
#OUTPATIENT_RATE,ASSETS_BUILDING_100BEDS,DOCTORS_100BEDS,PHARMACIST_100BEDS,NURSES_100BEDS
beta <- c(-19.44727,0.136413,0.783038,-3.057448,0.060976
       ,0.037199,-0.000805,0.579096,-1.267286,0.111931)
X <- cbind(general_beds,use_rate_general_beds,ave_stay_general,
           ave_impatient_per1day,outpatient_rate,assets_building_100beds,
           doctors_100beds,pharmacist_100beds,nurses_100beds)

predict_anb <- beta[1] +
              + beta[2]*general_beds + beta[3]*use_rate_general_beds + beta[4]*ave_stay_general +
              +beta[5]*ave_impatient_per1day + beta[6]*outpatient_rate + beta[7]*assets_building_100beds +
              +beta[8]*doctors_100beds + beta[9]*pharmacist_100beds + beta[10]*nurses_100beds


hbeta <- c(357.601606,0.001066,1.309320,-0.753807,-0.213619) 
X <- cbind(assets_building_100beds,doctors_100beds,nurses_100beds,ave_impatient_per1day)
hpredict_anb <- hbeta[1] + hbeta[2]*assets_building_100beds + hbeta[3]*doctors_100beds +
                + hbeta[4]*nurses_100beds + hbeta[5]*ave_impatient_per1day
hpredict_anb

write(predict_anb, file="predict_anb.txt")


x <- read.csv("impfe.txt")
attach(x) 
ls(x)
fe_using_imputated_data <- fe
plot(fe_using_imputated_data)
hist(fe_using_imputated_data,breaks =100)
?hist


a <- selection(DPCdummyH24 ~ assets_building_100beds + nurses_100beds
               + ave_impatient_per1day #+ ave_stay_general 
               + doctors_100beds + med_cost_per1man1day
               + use_rate_general_beds + pharmacist_100beds + outpatient_rate
               ,ambulance_month ~ 
               + pharmacist_100beds + doctors_100beds #+ general_beds
               + ave_impatient_per1day + assets_building_100beds + nurses_100beds 
               + med_cost_per1man1day 
               ,data = editeddata, weights= NULL, method = "2step")
summary(a)
options(scipen=10)
a$coefficients
a$vcov

#sample selection model

library(sampleSelection)
data4 <- read.csv("/Users/serubantesu2/Downloads/forhekit669panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data4)
data4
ls(data4)

#probit用データ
editeddata <- model.frame(DPCdummyH24 ~ year + assets_building_100beds 
                          + ave_impatient_per1day #+ ave_stay_general 
                          + doctors_100beds + nurses_100beds + med_cost_per1man1day
                          + use_rate_general_beds + pharmacist_100beds + outpatient_rate
                          + ambulance_month
                          ,data=data4)
length(editeddata$DPCdummyH24)
attach(editeddata)

DPCprobit <- glm( DPCdummyH24 ~ assets_building_100beds 
                    + ave_impatient_per1day #+ ave_stay_general 
                  + doctors_100beds + nurses_100beds + med_cost_per1man1day
                  + use_rate_general_beds + pharmacist_100beds + outpatient_rate
                  ,family = binomial( link = "probit"), data=data4)
summary(DPCprobit)

length(DPCdummyH24)
length(MrozDPC)


ls(editeddata)
MrozDPC <- invMillsRatio(DPCprobit)$IMR1
#Mroz0DPC <- invMillsRatio(DPCprobit)$IMR0
#cor(MrozDPC,Mroz0DPC)

usedata <- data.frame(editeddata, MrozDPC)
u <- subset(usedata, subset= DPCdummyH24 == 1)
imp <- subset(usedata, subset= DPCdummyH24 == 0)

write.table(u, file="hekit.txt")
write.table(imp, file="imp.txt")
datatemp <- read.csv("/Users/serubantesu2/Downloads/temp.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
dataimp <- read.csv("/Users/serubantesu2/Downloads/imp.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932")
attach(datatemp)
attach(dataimp)

HekitDPC <- lm( ambulance_month ~  year + outpatient_rate + doctors_100beds # + general_beds
                + nurses_100beds + ave_impatient_per1day + assets_building_100beds
                + MrozDPC
                , data = datatemp)  #+ u$MrozDPC

options(scipen=10)
summary(HekitDPC)
HekitDPC

x1 <- predict(HekitDPC, datatemp)
write(x1, file="x1.txt")
x <- read.csv("x1.txt")
x
summary(x1)
mean(x)
sd(x1)
hist(x1)



data4 <- read.csv("/Users/serubantesu2/Downloads/246panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data4)

public_panel_fixed <- plm(ambulance_month ~ assets_building_100beds + outpatient_rate + doctors_100beds # + general_beds
                          + nurses_100beds + ave_impatient_per1day
                          , data=data4, model="pooling") 
summary(public_panel_fixed)

OLS <- lm( ambulance_month ~  outpatient_rate + doctors_100beds # + general_beds
           + nurses_100beds + ave_impatient_per1day, data = data4)
summary(OLS)

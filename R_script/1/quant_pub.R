library(quantreg)
data(engel)

qr <- rq(foodexp~income,data=engel,tau=seq(0,1,0.25))
summary(qr)
qr

data6 <- read.csv("/Users/serubantesu2/Downloads/675cross.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data6)
data6
ls(data6)
data6

data7 <- read.csv("/Users/serubantesu2/Downloads/try2-2.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data7)
ls(data7)
data7

data8 <- read.csv("/Users/serubantesu2/Downloads/make717public_panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932")
attach(data8)
ls(data8)

forPSM <- model.frame(id ~ oldid + year + misOrder + kubun + ken + shi 
                         + name + forcheck + med_cost_per1man1day 
                         + med_cost + general_beds + use_rate_general_beds 
                         + ave_stay_general  + ave_impatient_per1day + out_patient 
                         + patient + outpatient_rate + assets_building_100beds 
                         + doctors_100beds + nurses_100beds + pharmacist_100beds 
                         + DPCdummyH20 + fixedeffect
                         , data = data7)

for717panel <- model.frame(id ~ year + kubun + ken + shi 
                      + name + forcheck + med_cost_per1man1day 
                      + medical_cost + general_beds + use_rate_general_beds 
                      + ave_stay_general  + ave_inpatient_per1day  #+out_patient 
                      + outpatient_rate + assets_building_100beds #+ patient 
                      + doctors_100beds + nurses_100beds + pharmacist_100beds 
                      #+ fixedeffect   + DPCdummyH20 
                      , data = data8)
length(for717panel$id)

write.table(forPSM, file="forPSM.txt", quote=F, col.names=T,append=F)

editeddata <- model.frame(DPCdummyH20 ~ fe + id + med_cost_per1man1day 
                          + general_beds + use_rate_general_beds
                          + ave_stay_general + ave_impatient_per1day + outpatient_rate
                          + assets_building_100beds + doctors_100beds + pharmacist_100beds
                          , data=data6)
ed <- editeddata 
write(ed$id, file="ed.txt")  
write.table(editeddata, file="ed.txt", quote=F, col.names=T, append=F)


reg <- lm(ed$med_cost_per1man1day ~ ed$DPCdummyH20 + ed$general_beds + ed$use_rate_general_beds
          + ed$ave_stay_general + ed$ave_impatient_per1day + ed$outpatient_rate
          + ed$assets_building_100beds + ed$doctors_100beds + ed$pharmacist_100beds
          , data=editeddata)
summary(reg)

qr <- rq(ed$med_cost_per1man1day ~ ed$general_beds + ed$use_rate_general_beds
         + ed$ave_stay_general + ed$ave_impatient_per1day + ed$outpatient_rate
         + ed$assets_building_100beds + ed$doctors_100beds + ed$pharmacist_100beds
         , data=editeddata, tau=seq(0,1,0.25))
summary(qr)
summary.rq(qr)
plot(qr)
qr


options(scipen=10)
qr <- rq(med_cost_per1man1day ~ general_beds + use_rate_general_beds
         + ave_stay_general + ave_impatient_per1day + outpatient_rate
         + assets_building_100beds + doctors_100beds + pharmacist_100beds
         #+ nurses_100beds
         , data=data7, tau=seq(0,1,0.25))

data4 <- read.csv("/Users/serubantesu2/Downloads/h25-17panel.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data4)
data4
ls(data4)

library(plm)

panel.fe <- plm(y ~ x1 + x2,data = data5, model = "within")
summary(panel.fe)

patients
medical_cost_1man = medical_cost / (365 * patients)
medical_cost_1man

public_panel_random <- plm(med_cost_per1man1day ~ general_beds + use_rate_general_beds
                           + ave_stay_general + ave_impatient_per1day + outpatient_rate
                           + assets_building_100beds + doctors_100beds + pharmacist_100beds
                           + DPCdummyH20
                           , data=data4, model="random") 
public_panel_fixed <- plm(med_cost_per1man1day ~ general_beds + use_rate_general_beds
                          + ave_stay_general + ave_impatient_per1day + outpatient_rate
                          + assets_building_100beds + doctors_100beds + pharmacist_100beds
                          + nurses_100beds
                          , data=data4, model="within") 

public_panel_fixed <- plm(medical_cost_per1day1man ~ general_beds + use_rates_general 
                          + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day
                          + fixed_assets_per1bed + doctor + nurse
                          , data=editeddata, model="within") 

cor(general_beds,areas_facility,use="complete.obs")
cor(general_beds,fixed_assets_per1bed,use="complete.obs")
cor(areas_facility,fixed_assets_per1bed,use="complete.obs")
cor(doctor,nurse,use="complete.obs")

editeddata <- model.frame(medical_cost_per1day1man ~ general_beds + use_rates_general 
                          + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day
                          + fixed_assets_per1bed + doctor + nurse
                          , data=data4)
length(editeddata$doctor)
data3 <- editeddata

options(scipen=10)
public_panel_random
public_panel_fixed
summary(public_panel_random)
summary(public_panel_fixed)
summary(fixef(public_panel_fixed))

fixef(public_panel_fixed)
write(fixef(public_panel_fixed), file="675fe.txt")
plot(fixef(public_panel_fixed))

x2 <- read.csv("703fe2.txt")
attach(x2)
x
hist(x2$fe)
ls(x)
plot(x)
hist(x2$fe,breaks =100, xlim=c(-50000,50000))
hist(Random.effect,breaks =100, xlim=c(-20000,20000))
plot(density(x2$fe,bw="nrd0",kernel="gaussian"), xlim=c(-50000,50000))
plot(density(Random.effect,bw="nrd0",kernel="gaussian"), xlim=c(-20000,20000))


?hist
y <- read.csv("246fenoam.txt") 
attach(y)
ls(y)
plot(fe3)
hist(x,breaks =100)

summary(fe2)
summary(fe3)
var(fe2)
var(fe3)

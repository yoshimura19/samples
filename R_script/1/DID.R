#DID

data10 <- read.csv("/Users/serubantesu2/Downloads/717public_panel_DID_2period.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data10)
data10
ls(data10)

data11 <- read.csv("/Users/serubantesu2/Downloads/717public_panel_DID_3period.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data11)
data11
ls(data11)

OLS <- lm(med_cost_per1man1day ~ H22Dummy + H22DPC + H22Dummy*H22DPC 
          + H21DPC
          + general_beds + use_rate_general_beds                            #↓共変量
          + ave_stay_general + ave_inpatient_per1day + outpatient_rate
          + doctors_100beds + pharmacist_100beds #+ assets_building_100beds 
          + nurses_100beds,data = data10)

DID <- lm(med_cost_per1man1day ~
            H23Dummy + H22Dummy + H23DPC + H22DPC + H23Dummy*H23DPC + H22Dummy*H22DPC 
          + H21DPC
          + general_beds + use_rate_general_beds                            #↓共変量
          + ave_stay_general + ave_inpatient_per1day #+ outpatient_rate
          + doctors_100beds + pharmacist_100beds +# assets_building_100beds 
          + nurses_100beds,data = data11)

options(scipen=10)
summary(OLS)
summary(DID)

cor(H22Dummy*H22DPC,H23Dummy*H23DPC)


public_panel_fixed <- plm(med_cost_per1man1day ~ general_beds + use_rate_general_beds
                          + ave_stay_general + ave_impatient_per1day + outpatient_rate
                          + assets_building_100beds + doctors_100beds + pharmacist_100beds
                          + nurses_100beds
                          , data=data4, model="within") 
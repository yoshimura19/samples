# ************** 効率性要因分析 **************** #


rm(list=ls())
data1 <- read.csv("/Users/serubantesu2/Downloads/panel_logit/efficient_analysis/efficient.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

aefficiency <- data1$efficiency * 100
#kango10under <- data1$kango7 + data1$kango10

ef <- lm(aefficiency ~ kenritsu + shiritsu	#+ hoka
          + houtekiyo	+ husaisan 
          + kango13over	+ kango7 #+ kango10  #+ kangokesson
          + use_rate_general + keijyou + igyousyushi #+ jishitsuigyou
         #+ hokkaido + tohoku + chubu + kinki + chugoku #+ kanto
         #+ shikoku + kyusyu + okinawa
         ,data = data1)
summary(ef)

head(data1[,7:20])
cor(data1[,7:20], use = "pairwise.complete.obs")

cor(data1$igyousyuushi,data1$keijyou, use = "pairwise.complete.obs")

?cor



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
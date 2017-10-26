data6 <- read.csv("/Users/serubantesu2/Downloads/675cross.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data6)
data6
ls(data6)

x <- read.csv("fixedeffect(-62).txt")
attach(x)
ls(x)
data.frame(x, data6)

logit.ps <- glm(DPCdummyH20 ~ general_beds + use_rate_general_beds
                + ave_stay_general + ave_impatient_per1day + outpatient_rate
                + assets_building_100beds + doctors_100beds + pharmacist_100beds
                + nurses_100beds
                + med_cost_per1man1day
                + fe
                ,family=binomial(link= "logit"), data=data6)
ps <- logit.ps$fitted
options(scipen=10)
summary(logit.ps)
ps

probit.ps <- glm(DPCdummyH20 ~ general_beds + use_rate_general_beds
                + ave_stay_general + ave_impatient_per1day + outpatient_rate
                + assets_building_100beds + doctors_100beds + pharmacist_100beds
                + nurses_100beds
                ,family=binomial(link= "probit"), data=data6)
summary(probit.ps)

#glmに使われたデータセット
editeddata <- model.frame(DPCdummyH20 ~ fe + id + general_beds + use_rate_general_beds
            + ave_stay_general + ave_impatient_per1day + outpatient_rate
            + assets_building_100beds + doctors_100beds + pharmacist_100beds
            , data=data6)
length(editeddata$id)
PSMid <- as.vector(editeddata$id)
write(editeddata$id, file="ps.txt")  


#PSを用いた線形回帰
editeddata$fe
length(fe)
ps.reg <- lm(editeddata$fe ~ editeddata$DPCdummyH20 + ps)
ps.reg <- lm(fe ~ DPCdummyH20 + ps)
summary(ps.reg)

#PSの逆数による重み付け平均IPW(inverse probability weighting)
y  <- editeddata$fe
z1 <- editeddata$DPCdummyH20
y  <- fe
z1 <- DPCdummyH20
ipwe1 <- sum((z1*y)/ps)/sum(z1/ps)
ipwe0 <- sum(((1-z1)*y)/(1-ps))/sum((1-z1)/(1-ps))
ipwe1              #処置の周辺平均（不偏一致推定量）
ipwe0              #not処置
ipwe1 - ipwe0     #因果効果


#漸近分散(星野p71)
treat <- (z1*(y-ipwe1)^2/(ps)^2)/(ps)^2
untreat <- ((1-z1)*(y-ipwe0)^2)/(1-ps)^2
N <- length(id)
IPWvar <- (1/N)* sum(treat + untreat)
IPWvar
IPWsd <- IPWvar^(1/2)
IPWsd
(ipwe1 - ipwe0) / IPWsd
var <- treat + untreat
plot(var)
hist(log(var))

pscheck <- data.frame(ps, z1)
write.table(pscheck, file="pscheck.txt")



ed <- editeddata 
#PS使わない重回帰(比較用)
reg <- lm(ed$fe ~ ed$DPCdummyH20 + ed$general_beds + ed$use_rate_general_beds
          + ed$ave_stay_general + ed$ave_impatient_per1day + ed$outpatient_rate
          + ed$assets_building_100beds + ed$doctors_100beds + ed$pharmacist_100beds
          , data=data6)
summary(reg)

reg <- lm(fe ~ DPCdummyH20 + general_beds + use_rate_general_beds
          + ave_stay_general + ave_impatient_per1day + outpatient_rate
          + assets_building_100beds + doctors_100beds + pharmacist_100beds
          , data=data6)
summary(reg)

rm(list=ls())
library(MASS)

summary(iris)
ls(iris)
data <- subset(iris, Species　=="versicolor" | Species == "virginica",select=c(3:4))   #花弁の長さと花弁の幅を使用

grouping <- as.matrix(subset(iris, Species　=="versicolor" | Species == "virginica",select=5))
grouping <- factor(grouping, label=c("e","i"))        #因子(カテゴリー変数)に変換

iris.lda <- lda(data, grouping, prior = c(1/2,1/2))  #線形判別
iris.qda <- qda(data, grouping, prior = c(1/2,1/2))  #2次判別

p1 <- predict(iris.lda)$class
table(grouping,p1)
p2 <- predict(iris.qda)$class
table(grouping,p2)

len <- 100
plot(data, type="n", xlim=c(2.5,7), ylim=c(0.5,3))   #type="n" 点を打たない
plot(data, type="n", xlim=c(2.5,7), ylim=c(0.5,3),xlab="Length", ylab="Width")
text(data, as.character(grouping), col=as.numeric(grouping)+1)
title(main="versicolor and virginica")
xp <- seq(2.5, 7, length = len)    #100 × 100のグリッドの定義
yp <- seq(0.5, 3, length = len)

cushT <- expand.grid(Petal.Length =xp, Petal.Width =yp)
Z <- predict(iris.lda, cushT)     # 線形判別でのグリッド上の事後確率
zp <- Z$posterior[,1] - Z$posterior[,2]    # aの事後確率 - bの事後確率
contour(xp, yp, matrix(zp, len), add=T, levels=0)   #等事後確率線
Z <- predict(iris.qda, cushT)

head(zp)
#ロジット判別
Petal.Length <- data[,1]
Petal.Width <- data[,2]
iris.logit <- glm(grouping ~ Petal.Length + Petal.Width, family = binomial(link= "logit"))
Z2 <- predict(iris.logit, cushT, type="response")    # y=2の確率(ここではi)
contour(xp, yp, matrix(Z2, len), add=T, level=0.5, col="purple")    #確率0.5の線


#多項式ロジット
PL <- Petal.Length
PW <- Petal.Width
iris.poly.logit <- glm(grouping ~ PL + I(PL^2) + PW + I(PW^2) + PW:PL, family=binomial(link="logit")) #推定×
Z3 <- predict(iris.poly.logit, cushT, type="response")
contour(xp, yp, matrix(Z3, len), add=T, levels=0.5, col="orange")     #確率0.5の線

#完全判別(perfect classifier)   x'bによって完全に判別されるためbが一意でない
dropobs <- c(21, 28, 57, 70, 84, 85, 121, 128) #削除する観測地の番号
data3 <- data[-dropobs,]    #完全判別のデータを人工的に作る
grouping3 <- grouping[-dropobs]
iris.lda3 <- lda(data3, grouping3)

dev.new()
plot(data3, type="n", xlim=c(2.5,7), ylim=c(0.5,3))
text(data3, as.character(grouping), col=as.numeric(grouping)+1)
title(main="Perfect classifier")

Z3 <- predict(iris.lda3, cushT)     # 線形判別でのグリッド上の事後確率
zp3 <- Z3$posterior[,1] - Z3$posterior[,2]    # aの事後確率 - bの事後確率
contour(xp, yp, matrix(zp3, len), add=T, levels=0)   #等事後確率線

Petal.Length <- data3[,1]
Petal.Width <- data3[,2]
iris.logit <- glm(grouping3 ~ Petal.Length + Petal.Width, family = binomial) #　ロジット判別
# 推定は収束しない


data6 <- read.csv("/Users/serubantesu2/Downloads/h21cross.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
data6 <- read.csv("/Users/serubantesu2/Downloads/h18cross.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data6)
data6
ls(data6)

data <- model.frame(DPCh21TF ~ medical_cost_per1day1man + general_beds + use_rates_general
                       + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day 
                    + fixed_assets_per1bed + doctor + nurse + areas_facility
                    ,data=data6)

data <- model.frame(DPCh21TF ~ medical_cost_per1day1man + general_beds + use_rates_general
                    + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day 
                    + fixed_assets_per1bed + doctor + nurse + areas_facility
                    + medical_revenue + non_medical_revenue 
                    ,data=data6)

data <- model.frame(DPCh21 ~ medical_cost_per1day1man + general_beds + use_rates_general
                    + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day 
                    + fixed_assets_per1bed + doctor + nurse + areas_facility
                    + medical_cost
                    + medical_revenue + non_medical_revenue + salary_doctor + allowance_doctor
                    ,data=data6)

subdata <- subset(data, select=c(2:length(data)))
DPC <- factor(data$DPCh21, label=c("F","T"))
DPC <- as.factor(data$DPCh21)
ls(subdata)
DPC

mode(DPC)
is.factor(DPCh21)
as.integer(DPCh21)
as.numeric(DPCh21)
DPCh21

DPCh21.qda <- qda(subdata, DPC)   #prior = c(1/2,1/2)
DPCh21.lda <- lda(subdata, grouping = DPC)   #prior = c(1/2,1/2)

summary(DPCh21.lda)
summary(DPCh21.qda)
DPCh21.qda
aiu <- DPCh21.lda
aiu

apply(DPCh21.lda$means %*% DPCh21.lda$scaling, 2, mean)  #定数項の計算
aiu$scaling

predict(aiu)$class
predict(DPCh21.lda)$class
predict(DPCh21.qda)$class
p1 <- predict(DPCh21.lda,subdata)$class
table(data$DPCh21,p1)
p2 <- predict(DPCh21.qda)$class
table(grouping,p2)

DPCh21 <- as.numeric(DPCh21TF)
attach(data)
length(data$general_beds)
length(DPCh21)
DPC.logit <- glm(DPCh21 ~ general_beds + use_rates_general
                 + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day
                 + fixed_assets_per1bed + doctor + nurse + areas_facility
                 + medical_revenue + non_medical_revenue
                   #medical_cost_per1day1man
                 , family = binomial(link= "logit"))

DPC.logit <- glm(DPC ~ general_beds + use_rates_general
                 + ave_stays_general + ave_inpatient_per1day + ave_outpatient_per1day
                 + fixed_assets_per1bed + doctor + nurse + areas_facility
                 + non_medical_revenue
                 #medical_cost_per1day1man
                 , family = binomial(link= "logit"))
Z2 <- predict(DPC.logit, cushT, type="response")    # y=2の確率(ここではi)

summary(DPC.logit)

library(systemfit)
library(lmtest)
library(sem)
library(sandwich)
library(MASS)
data10 <- read.csv("/Users/serubantesu2/Downloads/card.csv",header= T,sep=",",na.strings=".")
attach(data10)  #変数名取得
result <- lm(lwage ~ educ + exper + expersq + black + south + smsa + reg661 +
              + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66, data=data10)
summary(result)
#hausman.systemfit(educ,result)
result2 <- lm(educ ~ nearc4 + exper + expersq + black + south + smsa +
                + reg661 + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66, data=data10)
summary(result2)
result3 <- lm(nearc4 ~ iq)
summary(result3)
result4 <- lm(nearc4 ~ iq+smsa66+reg661+reg662+reg669)
summary(result4)
plot(data10$lwage , result2$res)
result6 <- tsls(lwage ~ educ + exper + expersq + black + south+ 
       + smsa + reg661 + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66,
        ~ nearc4 + exper + expersq + black + south + smsa + reg661 + 
       + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66,data = data10)
#
result6 <- tsls(lwage ~ educ + exper + expersq + black + south+ 
                  + smsa + reg661 + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66,
                ~ educ + exper + expersq + black + south + smsa + reg661 + 
                  + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66,data = data10)



summary(result6)
hausman.systemfit(result6,result)
bptest(result)
V <- sandwich(result)
diag(V)^(1/2)
rlm(lwage ~ educ + exper + expersq + black + south + smsa + reg661 +
  + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66, data=data10)
summary(rlm(lwage ~ educ + exper + expersq + black + south + smsa + reg661 +
              + reg662+reg663+reg664+reg665+reg666+reg667+reg668+smsa66, data=data10))


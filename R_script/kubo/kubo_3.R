#みどり本サポートHP: http://goo.gl/Ufq2
#directory:kubo
rm(list=ls())  
par(mfrow=c(1,1))


####### 6章 ########
#GLMの応用範囲を拡げる
#data4a.csv (ロジスティック回帰),data4b.csv (offset 項),d.RData (ガンマ分布 GLM)
rm(list=ls())
d <- read.csv("data4a.csv")
summary(d)
plot(d$x, d$y, pch = c(21, 19)[d$f])  #pchはプロットのマーカー
legend("topleft", legend = c("C","T"), pch = c(21, 19), cex = 1.2)

logistic <- function(z) { 1 / (1 + exp(-z)) }
x <- seq(-7, 7, 0.1)
z_0 <- x;   z_1 <- 2 + x;   z_2 <- 2 + 2*x;  z_3 <- -1*x 

plot.new()
plot(x, logistic(z_0), type = "l") ; abline(v = 0, lty=2) ; par(new=T)
plot(x, logistic(z_1), type = "l", col = 2) ; par(new=T)
plot(x, logistic(z_2), type = "l", col = 3) ; par(new=T)
plot(x, logistic(z_3), type = "l", col = 4) ; par(new=T)

logit_reg <- glm(cbind(y, N-y) ~ x + f, data = d, family = binomial)
summary(logit_reg)
plot(d$x, d$y, pch = c(21, 19)[d$f]) ;par(new=T)
xx <- seq(min(d$x), max(d$x), length = 100)
#? yy <- predict(logit_reg, newdata = data.frame(x = xx,fT), type = "responce")

library(MASS)
stepAIC(logit_reg)

#オフセット
rm(list=ls())
d <- read.csv("data4b.csv")
off_reg <- glm(y ~ x, offset = log(A), family = poisson, data = d)
summary(off_reg)

#ガンマ
load("d.RData")
gamma_reg <- glm(y ~ log(x), family = Gamma(link ="log"),data = d)
summary(gamma_reg)


###### 7章 ######
#一般化線形混合モデル(GLMM)
d <- read.csv("data.csv")
head(d)

plot(d$x, d$y) ; par(new=T)
model0 <- glm(cbind(y, N-y) ~ x, data = d, family = binomial) 
#plot(d$x, predict(model0), type = 'l', xlim =c(2,8), ylim = c(0,8))
xx <- seq(min(d$x), max(d$x), length = 100)
yy <- predict(model0, newdata = data.frame(x = xx), type = "response")
lines(xx, yy, lwd=2)

#葉数x_i= 4の分布を調べてみる
d4 <- d[d$x == 4,]
plot(table(d4$y))
c(mean(d4$y), var(d4$y))


###### 11章 #######


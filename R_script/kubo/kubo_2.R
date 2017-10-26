#みどり本サポートHP: http://goo.gl/Ufq2
#directory:kubo
rm(list=ls())
par(mfrow=c(1,1))

###### 2章 ######
#最尤推定
load("data.RData")

y <- 0:9
prob <- dpois(y, lambda = 3.56)
plot(y, prob, xlim=c(0,9), ylim=c(0,0.4), type = "b", lty = 2); par(new=T)

plot.new()
z <- rpois(100, 3.56)
hist(z, xlim=c(0,9) ,type = "l", lty = 1, ann=F)


LogL <- function(m){
    sum(dpois(data, m, log = TRUE))            #平均mと仮定した時のデータから計算した対数尤度
}
lambda <- seq(2, 5, 0.1)
plot(lambda, sapply(lambda, LogL), type = "l")  #リストに関数の適用
                                                #sapply() は結果のnames 属性付きのベクトル

#ポアソン分布の最尤推定量はhat(lambda)=(1/n)sum(y_i)
hat_lamda = sum(data) / length(data)



####### 3章 #########
#一般化線形モデル(GLM)
d <- read.csv("data3a.csv")
head(d)                      #x:個体の体サイズ、y:種子数、f:施肥処理
class(d)
summary(d)

par(mfrow=c(2,1))                     #データの概要の図示
plot(d$x, d$y, pch = c(21, 19)[d$f])
legend("topleft", legend = c("C", "T"), pch = c(21, 19))
plot(d$f, d$y)

fit <- glm(y ~ x, data = d, family = poisson(link = "log"))
summary(fit)
logLik(fit)      #このモデルの最大対数尤度


#推定結果 alpha_hat = 1.29, beta_hat = 0.0757
plot.new() ;par(mfrow=c(1,1))
plot(d$x, d$y, pch = c(21, 19)[d$f])        #pchはプロットのマーカー
xx <- seq(min(d$x), max(d$x), length = 100)   #a, b 間を n 等分する等差数列を生成．
lines(xx, exp(1.29 + 0.0757 * xx), lwd = 2)

yy <- predict(fit, newdata = data.frame(x = xx), type = "response")
lines(xx, yy, lwd = 2)


###### 4章 #######
#逸脱度 
#d <- read.csv("data3a.csv")
D_min <- (-2) * sum(log(dpois(d$y, lambda = d$y)))   #最小逸脱度(fullモデルの最大対数尤度)
dpois(1:10, lambda = 3) ; dpois(1:10, lambda = 1:10) #それぞれの値に対してそれぞれのlambdaを与える

#null model(最大の逸脱度を与える)
fit0 <- glm(y ~ 1, data = d, family = poisson(link = "log"))
summary(fit0)    #null devianceに注目

fit <- glm(y ~ x, data = d, family = poisson(link = "log"))
summary(fit)

###### 5章 #######
#尤度比検定
#d <- read.csv("data3a.csv")
fit0$deviance - fit$deviance     #逸脱度の改善量(尤度比の対数値*(-2))
#5.4.1 parametric bootstrap for 尤度比検定の統計量が従う分布の構成

{
    get.dd <- function(d) # データの生成と逸脱度差の評価 get data & deviance
    {
        n.sample <- nrow(d) #データ数
        #真のモデルからのデータによる逸脱度の差（↑統計量）の計算
        y.mean <- mean(d$y) #標本平均
        d$y.rnd <- rpois(n.sample, lambda = y.mean)  #帰無仮説の切片だけ(一定のlambda)モデルからのデータ
        fit1 <- glm(y.rnd ~ 1, data = d, family = poisson)
        fit2 <- glm(y.rnd ~ x, data = d, family = poisson)    
        fit1$deviance - fit2$deviance  #逸脱度の差    
    }
    
    pb <- function(d, n.bootstrap)  #d&dをparametric bootstrap.
    {
        replicate(n.bootstrap, get.dd(d))
    }
}

#シミュレーション
n.try <- 5000
dd12 <- pb(d, n.bootstrap = n.try)
hist(dd12, breaks = 30)
abline(v = 4.5, lty = 2)   #テキストで1回の試行で導かれた逸脱度の差  
sum(dd12 >= 4.5)    #シミュでn.try回中4.5より右にあるのはいくつか(histを見ながら)
P <- sum(dd12 >= 4.5) / n.try   #P値(ΔD_12>=4.5となる確率)
quantile(dd12, 0.95)  #sample quantile correspoinding to the given probabilities
                      #有意水準5%

#尤度比検定の統計量の漸近的性質
fit1 <- glm(y ~ 1, data = d, family = poisson)
fit2 <- glm(y ~ x, data = d, family = poisson)
anova(fit1, fit2, test = "Chisq")   #chi2分布 #サンプルサイズ大のとき


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

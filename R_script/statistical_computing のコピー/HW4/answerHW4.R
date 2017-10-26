rm(list=ls())
options(scipen=10)
plot.new()

### Setting
#setwd("/Users/kazuhikoshinki/WSU/Teach/MAT5030-14F/HW4")

X <- c(35, 90, 47, 45, 68, 70, 55)
Y <- c(21, 8, 16, 14, 11, 12, 10)

# 1(a)
plot(X,Y)

# 1(b)
lm(Y~X)
Call:
    lm(formula = Y ~ X)
Coefficients:
    (Intercept) X
24.7125 -0.1975

# 1(c)
XM <- cbind(rep(1, times=7), X)
solve(t(XM) %*% XM) %*% t(XM) %*% Y
[,1]
24.71247
X -0.19753

# 1(d)

sse <- function(beta){
        t(Y - beta[1] - beta[2]*X) %*% (Y - beta[1] - beta[2]*X)
        }
optim(c(0,0), sse)
$par
[1] 24.7146730 -0.1975471
$value
[1] 31.16438
$counts
function gradient
83 NA
$convergence
[1] 0
$message
1
NULL


2. (Chapter 6 Exercises 2)
### Exercise 2
attach(iris[1:50,])                       
n <- 50
LMi <- lm(Sepal.Length~Sepal.Width)
summary(LMi)                             #regress 0.4

plot(Sepal.Length~Sepal.Width) # scatter plot 
abline(LMi) # ... with regression line

Ylim <- range(Sepal.Length)
Xlim <- range(Sepal.Width)
CI <- predict(LMi, int="c") # confidence interval
PI <- predict(LMi, int="p") # prediction interval

CI <- CI[order(Sepal.Width),] # CI sorted by Sepal.Width
PI <- PI[order(Sepal.Width),] # PI sorted by Sepal.Width
CIPI <- cbind(CI,PI)
#CI
matlines(sort(Sepal.Width), CIPI[,1:3], xlim=Xlim, ylim=Ylim, col=c(1,2,2))
#PI
matlines(sort(Sepal.Width), CIPI[,4:6], xlim=Xlim, ylim=Ylim, col=c(1,3,3))


Solutions for Exercise 3 of Chapter 6 is as follows.
b <- LMi$coefficient # estimated beta
X <- cbind(rep(1,50), Sepal.Width)
X0 <- X # we choose x1, ..., xn as x0.
Df <- length(Sepal.Width)-2 # df for regression
t_a <- qt(0.975,df=Df) # t_{1-alpha/2}, alpha=0.05
S <- sqrt(sum(LMi$resid^2)/Df)
C <- sqrt(diag(X0 %*% solve(t(X) %*% X) %*% t(X0))) # for C.I.
P <- sqrt(diag(diag(n) + X0 %*% solve(t(X) %*% X) %*% t(X0))) # for P.I.
CIl <- fitted(LMi) - t_a * C * S # lower bounds for C.I. (sorted)
CIu <- fitted(LMi) + t_a * C * S # upper bounds for C.I. (sorted)
PIl <- fitted(LMi) - t_a * P * S # lower bounds for P.I. (sorted)
PIu <- fitted(LMi) + t_a * P * S # upper bounds for P.I. (sorted)
CIPI2 <- cbind(fitted(LMi), CIl, CIu, fitted(LMi), PIl, PIu)
CIPI2 <- CIPI2[order(Sepal.Width),] # should be the same as "CIPI"
# scatter plot, regression line with C.I. and P.I.
jpeg("iris-CIPI.jpg")
plot(Sepal.Width, Sepal.Length, xlim=Xlim, ylim=Ylim)
matlines(sort(Sepal.Width), CIPI[,1:3], xlim=Xlim, ylim=Ylim, col=c(1,2,2))
matlines(sort(Sepal.Width), CIPI[,4:6], xlim=Xlim, ylim=Ylim, col=c(1,3,3))
legend(2.5, 5.8, c("C.I.","P.I."), lty=1, col=2:3)
dev.off()
detach(iris[1:50,])
2


3

setwd("/Users/serubantesu2/Documents2/TA/16後期/statistical_computing/HW4")
3. (Literacy and GDP per capita)
(a)
Data <- read.table("GDPLiteracy.csv", sep=",", header=T)
GDP <- Data$GDPperCapita
LR <- Data$LiteracyRate
jpeg("LR-GDP.jpg"); plot(LR, GDP); dev.off()
plot(LR, GDP)
# Relationship is not linear.
# Large dispersion is observed for higher literacy rate.

(b)
LogGDP <- log(GDP)
jpeg("LR-logGDP.jpg"); plot(LR, LogGDP); dev.off()

(c)
LM <- lm(LogGDP~LR)
summary(LM)
Call:
    lm(formula = LogGDP ~ LR)
Residuals:
    Min 1Q Median 3Q Max
-2.6931 -0.7343 0.0471 0.6200 2.5307
Coefficients:
    Estimate Std. Error t value Pr(>|t|)
(Intercept) 3.931171 0.398668 9.861 <2e-16 ***
    LR 0.049377 0.004715 10.472 <2e-16 ***
    ---
    Signif. codes: 0 *** 0.001 ** 0.01 * 0.05 . 0.1 1
Residual standard error: 1.067 on 141 degrees of freedom
Multiple R-squared: 0.4375,Adjusted R-squared: 0.4335
F-statistic: 109.7 on 1 and 141 DF, p-value: < 2.2e-16
Intercept = 3:931171 (SD = 0:398668, t-stat = 9:861); slope = 0:049377 (SD =
                                                                            0:004715, t-stat 10:472). The slope is signicantly dierent from zero since p-value is
much smaller than 0.05.

(d)
PI <- predict(LM, int="p") # prediction band
PI <- PI[order(LR),] # PI sorted by Literacy rate
jpeg("LR-logGDP-PI.jpg")
Xlim <- range(LR)
Ylim <- range(LogGDP)
plot(LR, LogGDP, xlim=Xlim, ylim=Ylim)
matlines(sort(LR), PI, xlim=Xlim, ylim=Ylim , col=c(1,2,2))
dev.off()
4
Figure 1: Left: (a); Right: (b,d).

(e)
jpeg("LR-LogGDP-res.jpg"); plot(LR, resid(LM)); dev.off()
We have some curvature, i.e. both ends tend to have higher residuals and 60-80%
literacy rate tends to have lower residuals. This indicates some nonlinear relationship
between the variables. Also residuals have larger dispersion for higher literacy rate.

(f)
jpeg("LR-LogGDP-QQ.jpg"); qqnorm(resid(LM)); dev.off()
The residuals are approximately distributed as normal, since the plot is almost linear.
(g) We need variable(s) to explain a large dispersion among countries with a high literacy
rate. It may be good to add a measure of penetration of capitalism, since former (and
                                                                                  current) communist countries have a higher literacy rate but lower GDP per capita.
5
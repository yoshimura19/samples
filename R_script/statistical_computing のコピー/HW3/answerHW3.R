rm(list=ls())
options(scipen=10)
plot.new()


normmoment <- function(k, n=100000){
    mean(rnorm(n)^k)
}


normmoment(2,n=500000)
[1] 0.9966808
normmoment(4,n=500000)
[1] 2.994829
normmoment(6,n=500000)
[1] 14.95851
normmoment(8,n=500000)
[1] 106.8879



2. (Wilcoxon signed-rank test, Exercise 1 in Chapter 5 Slides p.36)
n <- 100
#n <- 10000
V <- numeric(n)
for (i in 1:n){
    V[i] <- wilcox.test(rnorm(7))$statistic
}
sum(V <= 9)
[1] 2358

sum(V <= 9) / 10000


3. (Test for equal variance; Welchs two-sample t-test)


# (a)
Male <- c(41, 51, 59, 38, 58, 55, 56, 72, 37, 74, 44, 38)
Female <- c(54, 62, 61, 58, 52, 55, 70)
jpeg("fig3a.jpg")
boxplot(Male, Female, names=c("male","female"))
dev.off()


# (b)
VM <- var(Male)
VF <- var(Female)
c(VM,VF) # sample variances
[1] 163.35606 37.47619
var.test(Male,Female) # F-test
F test to compare two variances
data: Male and Female
F = 4.3589, num df = 11, denom df = 6, p-value = 0.08345
alternative hypothesis: true ratio of variances is not equal to 1
95 percent confidence interval:
    0.8057526 16.9154837
sample estimates:
    ratio of variances
1
4.358929


# (c)
t.test(Male,Female)
Welch Two Sample t-test
data: Male and Female
t = -1.5936, df = 16.636, p-value = 0.1298
alternative hypothesis: true difference in means is not equal to 0
95 percent confidence interval:
    -16.144229 2.263277
sample estimates:
    mean of x mean of y
51.91667 58.85714


# (d)
VM <- var(Male)
VF <- var(Female)
c(VM,VF) # sample variances


nM <- length(Male)
nF <- length(Female)
>
TS <- (mean(Male) - mean(Female))/
    + sqrt(VM/nM+VF/nF) # t-statistic
DF <- (VM/nM + VF/nF)^2/
    + (VM^2/(nM^2*(nM-1))+VF^2/(nF^2*(nF-1))) # df
PV <- 2*min(pt(TS,df=DF),(1-pt(TS,df=DF)))
# two-sided p-value
c(TS,DF,PV)

[1] -1.5936496 16.6361743 0.1298351
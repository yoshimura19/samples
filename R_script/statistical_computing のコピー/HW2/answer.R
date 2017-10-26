rm(list=ls())
options(scipen=10)
plot.new()

ChickWeight
#異なる餌（diet1,2,3,4）で飼育された雛(50匹)の、日数（0,2,4,,,,,18,20,21day）と体重
#578サンプルからなるデータ
summary(ChickWeight)

prob1.
attach(ChickWeight)
Xlim <- range(Time)
Ylim <- range(weight)
for (i in 1:20){
    CWi <- ChickWeight[Chick==i,]
    plot(CWi$Time, CWi$weight,
         type="b", xlim=Xlim, ylim=Ylim,xlab="Time", ylab="Weight")
    par(new=T)
}
par(new=F)
detach(ChickWeight)

prob2.
# (a) sin 2*pi = 0.
# (b)
a <- 2 * pi
a # n = 1
[1] 6.283185
a - a^3/factorial(3) # n = 2
[1] -35.05852
# (c)
k <- 1
Ya <- a
while (abs(Ya) > 0.000001){
    k <- k + 1
    Ya <- Ya + (-1)^(k-1)*a^(2*k-1)/factorial(2*k-1)
    print(c(k,Ya)) # this line is not necessary
}
[1] 2.00000 -35.05852
[1] 3.00000 46.54673
[1] 4.00000 -30.15913
[1] 5.00000 11.89957
[1] 6.000000 -3.195076
[1] 7.0000000 0.6248765
[1] 8.00000000 -0.09324576
[1] 9.0000000 0.0109834
[1] 10.000000000 -0.001048183
[1] 1.100000e+01 8.274095e-05
[1] 1.200000e+01 -5.494384e-06
[1] 1.300000e+01 3.112686e-07
k
[1] 13
# n = 13 is the smallest number such that
# the approximation error is less than 0.000001


3.
# (a)
x <- c(1, 2, 3, 4, 5)
rsm <- function(x, n=100){
    sm <- numeric(n) # sample means by resampling
    for (i in 1:n){
        sm[i] <- mean(sample(x,replace=T)) #replace=T:復元抽出
    }                                       #要素の数を指定しない場合len(x)個とり出す
    sm
}


# (b)
x <- c(8.5, 7.5, 9.6, 13.6, 7.5, 7.7, 6.1, 5.5, 8.9, 8.6)
R <- rsm(x)
R
[1] 9.52 8.67 7.14 8.00 9.11 8.20 8.35 7.29 9.45 8.30 7.13 8.71 8.32 8.29 7.52
[16] 8.49 7.84 8.78 6.97 9.03 7.79 9.01 7.31 7.54 7.81 7.49 7.61 9.16 9.19 8.58
[31] 7.86 8.17 7.70 8.45 7.80 8.65 9.25 8.78 9.02 8.82 8.93 7.96 7.77 7.39 8.03
[46] 8.10 9.55 8.08 9.32 8.08 7.41 7.99 7.66 7.56 8.15 8.88 8.95 9.69 8.49 8.76
2
[61] 8.36 8.22 8.06 7.71 8.35 8.89 8.04 8.27 8.32 7.51 9.76 8.96 8.49 7.78 6.86
[76] 9.35 9.01 7.64 9.14 8.99 8.94 7.54 7.95 7.44 7.39 8.80 8.27 8.25 6.89 8.27
[91] 8.30 8.15 9.13 8.27 8.11 8.60 7.49 8.37 8.88 8.45
# (c)
sd(R)
[1] 0.6729227
# Note: Results vary. 10 additional runs returned:
# 0.6288037, 0.612087, 0.6771059, 0.6774417, 0.5912336,
# 0.7438684, 0.6761171, 0.5594394, 0.6762557, 0.6921625.


4.
M <- matrix(NA, nrow=35, ncol=10)
colnames(M) <- 0.01*(0:9)
rownames(M) <- -0.1*(34:0)
for (i in 1:35){
    for (j in 1:10){
        M[i,j] <- round(pnorm(-3.5 + 0.1*i - 0.01*(j-1)),4)
    }
}
M
#lecture9
nikkei <- read.table('nikkei.txt')
nikkei

source('trade2.R')
trade1(nikkei$V1,2,0.003)
trade2(nikkei$V1,2)
trade1ma(nikkei$V1,ep=0.0005)             #defautでm=5,ep=0.001
trade1ma(nikkei$V1,ep=0.0005,m=20)
trade2ma(nikkei$V1,ep=0.001)

plot.new()

ma(nikkei$V1)
plot.ts(nikkei$V1)
lines(ma(nikkei$V1),col=2)         #defのmは5
lines(ma(nikkei$V1,10),col=3)

#lecture10
nikkei <- read.table('nikkei.txt')
source('kalman.R')
lines(KF1(nikkei$V1,1,10),col=2)

library(timsac)
decomp(nikkei$V1,trend=1,ar=0,seasonal=0)  #decomposition 季節調整defaultはする
scan('nikkei.txt')
plot.ts(nikkei)
lines(nikkei.trend)

decomp(nikkei$V1,trend=2,ar=0,seasonal=0)
plot.ts(nikkei)
lines(nikkei.trend)

?decomp
#http://ssnt.ism.ac.jp     webでdecomp

#lecture11
data(Blsallfood)
decomp(Blsallfood, trade=TRUE, year=1973)

z <- decomp(nikkei$V1,trend=1,ar=0,seasonal=0,plot=F)
names(z)
par(mfrow=c(2,1))
plot.ts(z$trend)
plot.ts(z$noise)
x11()
lines(nikkei$V1,col=2)
plot.ts(z$ar)

for(i in 20:100) lines(decomp(nikkei$V1,trend=1,ar=0,seasonal=0,plot=F)$trend,col=i%%5+1)

#CAPMで推定
sony <- scan('sony.txt')
plot.ts(sony)
par(new=T)
plot.ts(nikkei,col=2)
plot(diff(log(nikkei$V1)),diff(log(sony)))
lsfit(diff(log(nikkei$V1)),diff(log(sony)),inter=F)$coef
#wind regression 20時点ごと回帰
for(i in 21:99) print(lsfit(diff(log(nikkei$V1))[(i-20):i],diff(log(sony))[(i-20):i]))$coefficients

#kalman varing coefficient
source('kalman.R')

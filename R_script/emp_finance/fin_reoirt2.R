library(FinTS)
data(m.ibmspln)

library(fUnitRoots)
ibm <- as.vector(m.ibmspln[,1])
sp <- as.vector(m.ibmspln[,2])
ibm
sp
unitrootTest(ibm, type = 'c', lags=1)  #ドリフト付きrandom walk
unitrootTest(sp, type = 'c', lags=1)

library(vars)
VARselect(m.ibmspln, lag.max = 5, type="const")  #SC(BIC)

var1 <- VAR(m.ibmspln, p=1, type = "const")
var2 <- VAR(m.ibmspln, p=3, type = "const")
summary(var1)

ip <- irf(var1, impluse = c('SP'),
          response = c('IBM','SP'),
          n.ahead = 5, boot = TRUE)
plot(ip)

?causality()
causality(var1, cause = "SP")
causality(var1, cause = 'IBM')


data3 <- read.csv("/Users/serubantesu2/Downloads/world_index_data.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data3)
ls(data3)
data3
dax_1

data4 <- read.csv("/Users/serubantesu2/Downloads/trial.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
data5 <- read.csv("/Users/serubantesu2/Downloads/trial3.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data5)
ls(data5)


unitrootTest(dax, type = 'c', lags=1)
?unitrootTest()
unitrootTest(nikkei225, type='c', lags=1)

"Date"      "dax"      "FTSE100"     "id"  "nikkei225"     "S.P500"     "SSE_composite_index"

n <- length(id)
nikkei225_1 <- rep(0,n-1) 
for(i in 2:n){
  SSE_composite_index_1[i-1] = SSE_composite_index_1[i] - nikkei225[i-1] 
}

library(fUnitRoots)
unitrootTest(nikkei225_1, type='c', lags=1)
unitrootTest(FTSE100_1, type='c', lags=1)
unitrootTest(dax_1, type='c', lags=1)
unitrootTest(S.P500_1, type='c', lags=1)
unitrootTest(SSE_composite_index_1, type="c", lags=1)
?unitrootTest

?data.frame
asset_indexes <- data.frame(dax_1,S.P500_1,SSE_composite_index_1,nikkei225_1)
asset_indexes
?VARselect()
VARselect(asset_indexes, lag.max = 5, type="const")  #SC(BIC)
var1 <- VAR(asset_indexes, p=2, type = "const")
summary(var1)
?VAR()

if( ((x[i] - x[i-1]) / x[i-1]) >  ep) {flg <-  1}
if(time[i] = 1){}
nikkei225_1[202]


nikkei225_1
rm(y)

predicted_y <- var3(100)
actual_y <- nikkei225_1[204:length(id)]           #length(id)
length(predicted_y)
length(actual_y)
plot.new()
plot(predicted_y, type = "l", col=2)
par(new=T)
plot(actual_y, type = 'l' ,)
actual_y
nikkei225[length(id)-1]
length(id) -1

vartrade(0.05)
vartrade(0.01)
vartrade(0.001)
vartrade(0.002)
vartrade(0.005)
vartrade(0.00005)
strvartrade(1,100,0.01)     #strvartrade(istart,n,ep)
strvartrade(1,100,0.002)
strvartrade(0.002)
strvartrade(1,100,0.005)
plot.new()
var3(100)
warnings()

vartrade <- function(ep)    #short sell version   (x,istart,n)
{
  x <- nikkei225[203:(length(id)-1)] #length(x)
  n <- length(x)
  res <- rep(0,n)
  pos <- 0
  #ep <- 0.005        #0.5%以上あがったら
  
  for(i in 1:n){
    flg <- 0
    if( predicted_y[i] > ep) {flg <- 1} 
    if( predicted_y[i] < -ep) {flg <- -1}
    
    #if( ((x[i] - x[i-1]) / x[i-1]) >  ep) {flg <-  1}
    #if( ((x[i] - x[i-1]) / x[i-1]) < -ep) {flg <- -1}
    
    if(pos == 0){              #ポジション取ってない
      if(flg == 1) {
        pos <- x[i]
        abline(v=i,col=4,lty=1)
      }
      if(flg == -1) {
        pos <- -x[i]
        abline(v=i,col=2,lty=1)
      }
    }
    else{　　　　　　　　　　　#ポジション取ってる
      if(pos > 0){
        res[i] <- x[i]-x[i-1]             #収益
        if(flg == -1){
          pos <- 0
          abline(v=i,col=2,lty=2)         #col=red, lty点線
        }
      }
      else{
        res[i] <- -(x[i]-x[i-1])
        if(flg == 1){
          pos <- 0
          abline(v=i,col=4,lty=2)
        }
      }
    }
  }
  ret <- sum(res)
  par(new=T)
  plot.ts(cumsum(res),col=3, lty=2)     #col=green
  return(ret)
}


var2 <- function(n)
  {
  for(i in 1:n){

    start <- length(nikkei225_1) - 100 + i-1   #取引スタート time=1,id=203,2015/1/27
    past <- i                             #time=-201,id=1,2014/4/10
    #過去200時点のデータを使いvar(2)モデルの推定
    #それぞれの系列は1期前との対数差分
    start
    y <- nikkei225_1[(past +3):start]      #startのデータは今期-前期のnikkei
    JPN_l1 <- nikkei225_1[(past + 2):(start-1)]    #var(2)モデルの推定
    JPN_l2 <- nikkei225_1[(past + 1):(start-2)]
    GER_l1 <- dax_1[(past + 2):(start-1)]
    GER_l2 <- dax_1[(past + 1):(start-2)]
    USA_l1 <- S.P500_1[(past + 2):(start-1)]
    USA_l2 <- S.P500_1[(past + 1):(start-2)]
    CHI_l1 <- SSE_composite_index_1[(past + 2):(start-1)]
    CHI_l2 <- SSE_composite_index_1[(past + 1):(start-2)]
    CONS <- rep(1,length(y))              #定数項　length(y)=200

    x <- cbind(CONS,JPN_l1,JPN_l2,GER_l1,GER_l2,USA_l1,USA_l2,CHI_l1,CHI_l2)   #説明変数行列
    beta <- solve(t(x) %*% x) %*% t(x) %*% y                 #varモデルは各方程式をOLS

    #beta  #OLS
    y_hat = x %*% beta
    error = y - y_hat

    #予測 (1期先予測)
    predicted_y = 
    beta[1] + beta[2]*nikkei225_1[start] + beta[3]*nikkei225_1[start -1] +
    beta[4]*dax_1[start] + beta[5]*dax_1[start -1] +
    beta[6]*S.P500_1[start] + beta[7]*S.P500_1[start -1] +
    beta[8]*SSE_composite_index_1[start] + beta[9]*SSE_composite_index_1[start -1]
    #nikkei225_1[start]
    #predicted_y                    #start203時点のデータを使って1期先204時点を予測
    return(predicted_y)
    }
}
  

result_2 <- lm(conv ~ pop + car + nm_f_30, data = cvdata)
lm(y ~ y_1 + y_2)
library(stats)
arima(y, order = c(2,0,0), method = "CSS-ML" ,include.mean = TRUE)
?arima


plot( , type = 'l')
ls(data4)
id

#１章演習(沖本)
data1 <- read.csv("/Users/serubantesu2/Downloads/economicdata.csv",header= T,sep=",",na.strings=".")
attach(data1)
plot(topix,type="l")
plot(indprod,type="l")

data2 <- read.csv("/Users/serubantesu2/Downloads/economicdata (対数).csv",header= T,sep=",",na.strings=".")
data2
attach(data2) #エラー??
plot(data2$log_topix,type="l")
log_topix <- data2$log_topix[2:364]
acf(log_topix)
data2$log_indprot
log_indprot <- data2$log_indprot[2:364]
acf(log_indprot)　　　　　　　　　　　#自己相関
pacf(log_indprot)                    #偏自己相関

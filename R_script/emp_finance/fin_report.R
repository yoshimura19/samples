rm(data2)
data3 <- read.csv("/Users/serubantesu2/Downloads/world_index_data.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data3)
plot(nikkei225,type="l",col=1) #black
par(new=T)
plot(dax,type="l",col=2)  #red
plot(SSE_composite_index,type="l",col=3)  #green
plot(S.P500,type="l",col=4)  #blue
plot(FTSE100,type="l",col=6)  #purple

data3
nikkei225      dax SSE_composite_index S.P500 FTSE100

trade2 <- function(x,istart,n)    #short sell version(空売りver)
{
  length(x)
  res <- rep(0,n)
  pos <- 0
  ep <- 0.005        #0.5%以上あがったら
  
  for(i in istart:n){
    flg <- 0
    
    if( ((x[i] - x[i-1]) / x[i-1]) >  ep) {flg <-  1}        #ここは作り替える!
    # if( subfunc(x[1:i]) > ep ) flg <- 1                    #epはadhocでok
    if( ((x[i] - x[i-1]) / x[i-1]) < -ep) {flg <- -1}
    
    
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

# dump(c("dummy","trade1","subfunc"))    #で作って欲しい

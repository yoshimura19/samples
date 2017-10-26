#lecture8
trade1 <- function(x,istart,n)              #何期からスタートか
{
  length(x)
  res <- rep(0,n)
  pos <- 0
  ep <- 0.005        #0.5%以上あがったら
  
  for(i in istart:n){
    flg <- 0
    if( ((x[i] - x[i-1]) / x[i-1]) >  ep) {flg <-  1}
    if( ((x[i] - x[i-1]) / x[i-1]) < -ep) {flg <- -1}
    
    if(pos == 0){              #ポジション取ってない
      if(flg == 1) {
        pos <- x[i]
        abline(v=i,col=4)
      }
    }
    else{
      res[i] <- x[i]-x[i-1]
      if(flg == -1){
        pos <- 0
        abline(v=i,col=2,lty=2)         #col=red, lty点線
      }
    }
  }
  ret <- sum(res)
  par(new=T)
  plot.ts(cumsum(res),col=3, lty=2)     #col=green
  return(ret)
}

plot.ts(exp(10+cumsum(rnorm(100) * 0.01)))
plot.new()

trade2 <- function(x,istart,n)    #short sell version(空売りver)
{
  length(x)
  res <- rep(0,n)
  pos <- 0
  ep <- 0.005        #0.5%以上あがったら
  
  for(i in istart:n){
    flg <- 0
    if( ((x[i] - x[i-1]) / x[i-1]) >  ep) {flg <-  1}
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

#plot.ts(exp(10+cumsum(rnorm(100) * 0.01)))
#plot.new
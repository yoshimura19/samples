#lecture8
plot.new()


trade1 <- function(x,istart,ep)              #何期からスタートか
{
  plot.new()
  plot.ts(x)
  n <- length(x)
  res <- rep(0,n)
  pos <- 0
 # ep <- 0.005        #0.5%以上あがったら
  
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

#plot.ts(exp(10+cumsum(rnorm(100) * 0.01)))

trade2 <- function(x,istart)    #short sell version(空売りver)
{
  plot.new()
  plot.ts(x)
  n <- length(x)
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

#lec9
#移動平均MAを作る    
ma <- function(x,m=5)
{
  n <- length(x)
  res <- rep(NA,n)     #NAをとりあえず並べておく
  for(i in m:n){
    res[i] <- mean(x[(i-m+1):i])        #i時点を含む過去m個
  }
return(res)
}

#改良ver         ミスありで動かない
ma2 <- function(x,m=5)
{
  n <- length(x)
  z <- x
  for(i in 2:m){
    z<- cbind(z,x[i:n])
  }
  z <- z[1:(n-m+1)]
  res <- apply(z,1,mean)
  res <- c(rep(NA,m-1),res)
return(res)
}

trade1ma <- function(x,istart=m+1,ep=0.001,m=5)              #何期からスタートか
{                                                        #istart > m (xmaのデータがある)
  plot.new()
  plot.ts(x)
  n <- length(x)
  
  xma <- ma(x,m)
  lines(xma,col=2)   #col=red
  #browser()             #デバック
  
  res <- rep(0,n)
  pos <- 0
  # ep <- 0.005        #0.5%以上あがったら
  
  for(i in istart:n){
    flg <- 0
    if( ((xma[i] - xma[i-1]) / xma[i-1]) >  ep) {flg <-  1}
    if( ((xma[i] - xma[i-1]) / xma[i-1]) < -ep) {flg <- -1}
    
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


trade2ma <- function(x,istart=m+1,ep=0.001,m=5)    #short sell version(空売りver)
{
  plot.new()
  plot.ts(x)
  n <- length(x)
  
  xma <- ma(x,m)
  lines(xma,col=2)   #col=red
  #browser()             #デバック
  
  res <- rep(0,n)
  pos <- 0
  #ep <- 0.005        #0.5%以上あがったら
  
  
  
  for(i in istart:n){
    flg <- 0
    if( ((xma[i] - xma[i-1]) / xma[i-1]) >  ep) {flg <-  1}
    if( ((xma[i] - xma[i-1]) / xma[i-1]) < -ep) {flg <- -1}
    
    if(pos == 0){              #ポジション取ってない
      if(flg == 1) {
        pos <- x[i]
        abline(v=i,col=4,lty=1)    #blue  普通の線
      }
      if(flg == -1) {
        pos <- -x[i]
        abline(v=i,col=2,lty=1)    #red　普通の線
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


trade1dec <- function(x,istart=m+1,ep=0.001,m=1)              #何期からスタートか
{                                                        #istart > m (xmaのデータがある)
  plot.new()
  plot.ts(x)
  n <- length(x)
  
  xma <- ma(x,m)
  lines(xma,col=2)   #col=red
  #browser()             #デバック
  
  res <- rep(0,n)
  pos <- 0
  # ep <- 0.005        #0.5%以上あがったら
  
  for(i in istart:n){
    flg <- 0
    if( ((xma[i] - xma[i-1]) / xma[i-1]) >  ep) {flg <-  1}
    if( ((xma[i] - xma[i-1]) / xma[i-1]) < -ep) {flg <- -1}
    
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
#lecture7
foo <- function(x1,y1,x2,y2)
{
z <- sum((c(x1,y1)-c(x2,y2))^2) + zz　#ローカル変数
return(sqrt(z))
}
foo(1,2,3,4)

zz <- 5   #グローバル変数
ls()

# 宿題？
# ランダムウォークのシミュレーション

data(iris)
iris
attach(iris)
plot(iris$Petal.Length,iris$Species, col = 1)

corre[1] <- 1
iteration <- 1000
for (j in 1:iteration){
  time <- 100
  x1[1] <- rnorm(1)
  for (i in 2:time){
    x1[i] <- x1[i-1] + rnorm(1)
  }
  x2[1] <- rnorm(1)
  for (i in 2:time){
    x2[i] <- x2[i-1] + rnorm(1)
  } 
  corre[j] <- cor(x1[], x2[])
}

corre[]
mean(corre[])
var(corre[])
summary(corre[])



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


predicted_y <- var2(100)     #time=204時点からの予測
predicted_y




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

plot.ts(exp(10+cumsum(rnorm(100) * 0.01)))
plot.new




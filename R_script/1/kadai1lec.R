nsim=0
rwcor <- function(n=100,nsim=100000)
{
  rho <- rep(0,nsim)     #領域確保&初期化
  for(j in 1:nsim){       
    x1 <- rep(0,n)
    x2 <- rep(0,n)
    for(i in 2:n){
      x1[i] <- x1[i-1] + rnorm(1)
      x2[i] <- x2[i-1] + rnorm(1)
    }
    rho[j] <- cor(x1,x2)
  }
  hist(rho)
  return(list(mean=mean(rho),var=var(rho)))
}



nsim=0   #for文を避ける処理
rwcor2 <- function(n=100,nsim=100000)
{
  rho <- rep(0,nsim)     #領域確保&初期化
  for(j in 1:nsim){       
    x1 <- rep(0,n)
    x2 <- rep(0,n)
    x1 <- cumsum(rnorm(n))             #for文を避ける処理
    x2 <- cumsum(rnorm(n))             #cumsum(1:3) 1 3 6  (1,1+2,3+3)
    rho[j] <- cor(x1,x2)
  }
  hist(rho)
  return(list(mean=mean(rho),var=var(rho)))
}



rwcor3 <- function(n=100,nsim=10000)
{
  k <- as.integer(sqrt(2*nsim)) + 1
  x <- apply(matrix(rnorm(n*k), ncol=k),2,cumsum)
 mat <- cor(x)
 rho <- mat[col(mat) > row(mat)]
 print(length(rho))
 hist(rho)
 return(list(mean=mean(rho),var=var(rho)))
}
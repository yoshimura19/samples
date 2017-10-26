source("fin_reoirt2.R")


foo <- function(x1=y2,y1,x2=0,y2=2)
{

if(x1 < 0) stop(" x1  < 0")
for(i in 1:10) {
z <- sum((c(x1,y1)-c(x2,y2))^2)+zz
zz <- z
}

return(as.character(z)*2)
}
foo2 <- function(x)
{
return()
}

rwcor <- function(n=100,nsim=1000)
{
rho <- rep(0,nsim)

for(j in 1:nsim) {
x1 <- rep(0,n)
x2 <- rep(0,n)
for(i in 2:n) {
x1[i] <- x1[i-1]+rnorm(1)
x2[i] <- x2[i-1]+rnorm(1)
}
rho[j] <- cor(x1,x2)
}
hist(rho)
return(list(mean=mean(rho),var=var(rho)))
}
rwcor2 <- function(n=100,nsim=1000)
{
rho <- rep(0,nsim)
for(j in 1:nsim) {
x1 <- cumsum(rnorm(n))
x2 <- cumsum(rnorm(n))
rho[j] <- cor(x1,x2)
}
hist(rho)
return(list(mean=mean(rho),var=var(rho)))
}

rwcor3 <- function(n=100,nsim=1000)
{
k <- as.integer(sqrt(2*nsim))+1
x <- apply(matrix(rnorm(n*k),ncol=k),2,cumsum)
mat <- cor(x)
rho <- mat[col(mat) > row(mat)]
print(length(rho))
hist(rho)
return(list(mean=mean(rho),var=var(rho)))
}

trade1 <- function(x,istart,ep=0.005)
{
plot.ts(x)
n <- length(x)
res <- rep(0,n)
pos <- 0 

for(i in istart:n) {
 flg <- 0
 if( (x[i]-x[i-1])/x[i-1] > ep) flg <- 1
 if( (x[i]-x[i-1])/x[i-1] < -ep) flg <- -1

 if(pos == 0) {
   if(flg == 1) { pos <- x[i]
                 abline(v=i,col=4,lty=2)
                }
   }
   else {
     res[i] <- x[i]-x[i-1]
     if(flg == -1) {
       abline(v=i,col=2,lty=2)
       pos <- 0
     }
   }
}
ret <- sum(res)
par(new=T)
plot.ts(cumsum(res),col=3, lty=2, yaxt="n",ylab="")
axis(4)
return(ret)
}

trade2 <- function(x,istart,ep=0.005)
{
## short sell version
plot.ts(x)
n <- length(x)
res <- rep(0,n)
pos <- 0 

for(i in istart:n) {
 flg <- 0
 if( (x[i]-x[i-1])/x[i-1] > ep) flg <- 1
 if( (x[i]-x[i-1])/x[i-1] < -ep) flg <- -1

 if(pos == 0) {
   if(flg == 1) { pos <- x[i]
                 abline(v=i,col=4,lty=1)
                }
   if(flg == -1) { pos <- -x[i]
                 abline(v=i,col=2,lty=1)
                }

   }
   else {
     if(pos > 0) {
     res[i] <- x[i]-x[i-1]
     if(flg == -1) {
       abline(v=i,col=2,lty=2)
       pos <- 0
     }

      }
      else {
      res[i] <- -(x[i]-x[i-1])
     if(flg == 1) {
       abline(v=i,col=4,lty=2)
       pos <- 0
     }


      }

   }
}
ret <- sum(res)
par(new=T)
plot.ts(cumsum(res),col=3, lty=2, yaxt="n",ylab="")
axis(4)
return(ret)
##  trade1(exp(10+cumsum(rnorm(100)*0.01)),istart=2)
###next filter rule
}
ma1 <- function(x,m=5)
{
 n <- length(x)
 res <- rep(NA,n)
 for(i in m:n) {
 res[i] <- mean(x[(i-m+1):i])
 }
return(res)
}
ma <- function(x,m=5)
{
 n <- length(x)
 z <- x
 for(i in 2:m) {
 z <- cbind(z,x[i:n])
 }
 z <- z[1:(n-m+1),]
 res <- apply(z,1,mean)
 res <- c(rep(NA,m-1),res)
return(res)
}
trade1ma <- function(x,istart=m+1,ep=0.001,m=5)
{ # istart > m
plot.ts(x)
n <- length(x)

xma <- ma1(x,m)
lines(xma,col=2)

res <- rep(0,n)
pos <- 0 

for(i in istart:n) {
 flg <- 0
 if( (xma[i]-xma[i-1])/xma[i-1] > ep) flg <- 1
 if( (xma[i]-xma[i-1])/xma[i-1] < -ep) flg <- -1

 if(pos == 0) {
   if(flg == 1) { pos <- x[i]
                 abline(v=i,col=4,lty=2)
                }
   }
   else {
     res[i] <- x[i]-x[i-1]
     if(flg == -1) {
       abline(v=i,col=2,lty=2)
       pos <- 0
     }
   }
}
ret <- sum(res)
par(new=T)
plot.ts(cumsum(res),col=3, lty=2, yaxt="n",ylab="")
axis(4)
return(ret)
}
trade2ma <- function(x,istart=m+1,ep=0.001,m=5)
{
## short sell version
plot.ts(x)
n <- length(x)

xma <- ma1(x,m)
lines(xma,col=2)

res <- rep(0,n)
pos <- 0 

for(i in istart:n) {
 flg <- 0
 if( (xma[i]-xma[i-1])/xma[i-1] > ep) flg <- 1
 if( (xma[i]-xma[i-1])/xma[i-1] < -ep) flg <- -1

 if(pos == 0) {
   if(flg == 1) { pos <- x[i]
                 abline(v=i,col=4,lty=1)
                }
   if(flg == -1) { pos <- -x[i]
                 abline(v=i,col=2,lty=1)
                }

   }
   else {
     if(pos > 0) {
     res[i] <- x[i]-x[i-1]
     if(flg == -1) {
       abline(v=i,col=2,lty=2)
       pos <- 0
     }

      }
      else {
      res[i] <- -(x[i]-x[i-1])
     if(flg == 1) {
       abline(v=i,col=4,lty=2)
       pos <- 0
     }


      }

   }
}
ret <- sum(res)
par(new=T)
plot.ts(cumsum(res),col=3, lty=2, yaxt="n",ylab="")
axis(4)
return(ret)
##  trade1(exp(10+cumsum(rnorm(100)*0.01)),istart=2)
###next filter rule
}
KF1 <- function(x,Q,R=1)
{
n <- length(x)
z <- x
V <- rep(Q/4,n)
for(i in 2:n) {
  K <- (V[i-1]+Q)/(V[i-1]+Q+R)
  if(is.na(x[i])) {
     z[i] <- z[i-1]
     V[i] <- V[i-1]+Q
   }
  else {
     z[i] <-z[i-1]+K*(x[i]-z[i-1])
     V[i] <- (1-K)*(V[i-1]+Q)
   }
}
return(z)
}

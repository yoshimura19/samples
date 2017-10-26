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
print("ランダムウォークのsumary")
print(summary(corre[]))


cumsum(1:3)
cumsum(rep(1,10))

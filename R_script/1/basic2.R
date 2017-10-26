date()
myabs <- function(x,y)       #関数定義
  if (x-y < 0){
    abs = -(x-y)
    return (abs)
  } else {
    (x-y >= 0)
    abs = x-y
    return (abs)
  }

myabs(2,3)

myplus <- function(x){
  sum <- 0
  for(j in 1:length(x)){
    if(!is.na(x[j]))
      sum <- sum + x[j] 
  }
  return(sum)
}

x <- c(1,2,3,NA,4,5,NA) 
myplus(x)
y <- c(1,2,3,4,5)
myplus(y)

f <- function(x) exp(x) - 2　　#ニュートン法
uniroot(f, c(0,1))

f <- function(x) x^2 - 2*x
uniroot(f,c(1,3))

round(polyroot(c(-2,5,4,1)),digit=3) #多項式 x^3+4x^2+5x-2の解

f <- expression( a*x^4 )
D(f, "x") #D(数式,微分する変数)

DD <- function(expr, name, order = 1){  #DD 高階微分定義 (関数,変数,微分する関数)
  if(order < 1) stop("'order' must be >= 1")
  if(order == 1) D(expr, name)
  else DD(D(expr, name), name, order - 1)
}
DD(f, "x",3)

f <- deriv(~ x^2, "x", func=T ) #deriv(~数式, 微分する変数, func=T)
f(-2)
g <- deriv(~ x^2*y, c("x","y"), func = TRUE) #多変数の微分
g(2,3)
h <- deriv(~ x^2*y*z, c("x","y"), function(x, y, z=4){} ) #関数の形指定
h(3,2)

round(polyroot(c(1,-0.3,0.7)),digit=3) 

#数値積分
f <- function(x) x^2
integrate(f, 0, 1)  #(被積分関数,積分範囲の下限,上限)

integrate(sin, 0, pi)

integrate(dnorm, -Inf, 1.96)  # dnorm:正規分布の分布関数 広義積分

#行列の作成と基本操作
x <- matrix(1:6, nrow=2, ncol=3)
matrix(1:6, nrow=2, ncol=3, byrow=T)
x[c(1,2), 2]

library()

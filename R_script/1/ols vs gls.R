### OLS vs GLS ###
#under_construction サンプル数についての推定量の挙動をグラフ化するのが目標
#サンプルサイズについては完了

#生成データを不均一分散とする
#!モデルy = alpha + beta*x + e
rm(list=ls())

#①(sigma_i)^2 = (sigma^2) * ((x_i)^2)  (Xに関して単調な増加関係)
#この不均一分散の場合，誤差項間の相関はないのでolsと係数は一致するはず？

alpha = 2  #真のパラメタ
beta = 5
sigma <- 1

#出力用
b_ols <- c()
b_gls <- c()
var_b_ols <- c()
var_b_gls <- c()
end <- 70 #n=1000 when end=40, n=10000 when end=90
#as.integer((1.05)^(100+end))

#サンプルサイズに関して調べ(ここからループ)
sample_size <- c()
for (j in 1:end){
    n <- sample_size[j] <- as.integer((1.05)^(j+100))    #生成データ数n
    #options(scipen=10)
    #sample_size
  
    var_cov_matrix <- (matrix(rep(0,n*n), n,n))    #撹乱項の分散共分散行列（初期化）

    #sigma_iの生成
    #rm(x,y)
    x <- rnorm(n, mean=20, sd=5)                #説明変数
    sigma_i <- sqrt((sigma * x)^2)              #sigma = 1 ①のモデル参照
    var_cov_matrix <- diag((sigma_i)^2)         #対角要素に代入
    #diag(var_cov_matrix)                       #確認用
  
    sd <- sqrt(diag(var_cov_matrix))      #多変量正規分布でも出来るが分かり易さのため作成
    y <- c()
    for (i in 1:n){
        y[i] <- alpha + beta * x[i] + rnorm(1, mean=0, sd[i])
    }
    #plot(x,y)  #生成データ，xとyの散布図
  
  
     # 推定 #
    #説明変数行列の作成
    c <- rep(1,n)      #和ベクトル
    X <- cbind(c,x)
    intercept <- c(rep(0,2)) 
    vcov <- matrix(rep(0,2*2),2,2)
    vcov_diag <- c(rep(0,2))
  
        #OLS
    intercept <- solve(t(X) %*% X) %*% t(X) %*% y    #b_ols = (X'X)^(-1) X'y
    b_ols[j] <- intercept[2]
    zansa <- y - (X %*% intercept)
    sigma_hat <- sqrt( (1 / (n - 2)) * ( t(zansa) %*% zansa))
    vcov <- as.numeric(sigma_hat^2) * solve(t(X) %*% X)  #var(b_ols) = (σ^2)*(X'X)^(-1)
    vcov_diag <- diag(vcov)
    var_b_ols[j] <- vcov_diag[2]
    #sqrt(diag(var_b_ols))                             #推定された係数の分散共分散行列
          
    ###
    #b_ols_pack <- lm(y ~ x)   #確認用パッケージ（上と一致を確認）
    #summary(b_ols_pack)
    #vcov(b_ols_pack)
    ###
          
    #GLS  (今回は真の分散共分散行列が分かっているのでF-GLSではない)
    Omega <- var_cov_matrix            #真の分散共分散行列
    #いまは対角行列なので高速化する
    inv_Omega <- diag(1/c(diag(Omega)))
    #intercept <- solve(t(X) %*% solve(Omega) %*% X) %*% (t(X) %*% solve(Omega) %*% y)  #b_gls = (X'Ω^(-1)X)^(-1) *X'Ω^(-1)y
    intercept <- solve(t(X) %*% inv_Omega %*% X) %*% (t(X) %*% inv_Omega %*% y)
    b_gls[j] <- intercept[2]
    vcov <- sigma^2 * solve(t(X) %*% inv_Omega %*% X)       #var(b_gls) = (σ^(2))*(X'Ω^(-1)X)^(-1)
    vcov_diag <- diag(vcov)
    var_b_gls[j] <- vcov_diag[2]
    
    ###
    #library(nlme)                #確認用パッケージ
    #b_gls_pack <- gls(y ~ x,)    #共分散行列の与え方調べ中...
    #summary(b_gls_pack)
    #vcov(b_gls_pack)
    ###
  
  
    #まとめ# jで管理，簡単にbetaの係数だけ．
    print(j); print(n)
    #b_ols[j]
    #b_gls[j]
    #var_b_ols[j]
    #var_b_gls[j]
}


if(0){
plot.new()
par(mfrow=c(2,1)) 
plot(sample_size,b_ols, type="l", ylim=c(4.5,5.5), col=2, ann = F) ;par(new=T)
plot(sample_size,b_gls, main="OLS vs GLS", type="l", ylab="beta",ylim=c(4.5,5.5), col=3)
plot(sample_size,log10(var_b_ols), type="l", col=2, ann = F, ylim=c(-4,-1.0)) ;par(new=T)
plot(sample_size,log10(var_b_gls), main="OLS vs GLS",ylab="log10(var(beta))", type="l", col=3, ylim=c(-4,-1.0))
}
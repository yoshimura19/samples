data <- read.csv("/Users/serubantesu2/Downloads/yoshimura_kadai.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
attach(data)
ls(data)

i <- 1
#start

strvar <- function(i)
{
  #predicted_y <- numeric(n)
  #for(i in 1:n){
    
    start <- length(nikkei225_1) - 100 + i-1   #i=1から取引スタート可 time=1,id=203,2015/1/27 i=100でtime=100,2015,6,17
    past <- i                                  #time=-201,id=1,2014/4/10
    #過去200時点のデータを使いstrvar(2)モデルの推定
    #それぞれの系列は1期前との対数差分（収益率のデータ）
    #非説明変数
    JPN <- nikkei225_1[(past +3):start]      #startのデータは今期-前期のnikkei
    GER <- dax_1[(past +3):start]
    USA <- S.P500_1[(past +3):start]
    CHI <- SSE_composite_index_1[(past +3):start]
    
    #説明変数
    intercept <- rep(1,length(JPN))              #定数項　length(y)=200
    JPN_l1 <- nikkei225_1[(past + 2):(start-1)]    #var(2)モデルの推定
    JPN_l2 <- nikkei225_1[(past + 1):(start-2)]
    GER_l1 <- dax_1[(past + 2):(start-1)]
    GER_l2 <- dax_1[(past + 1):(start-2)]
    USA_l1 <- S.P500_1[(past + 2):(start-1)]
    USA_l2 <- S.P500_1[(past + 1):(start-2)]
    CHI_l1 <- SSE_composite_index_1[(past + 2):(start-1)]
    CHI_l2 <- SSE_composite_index_1[(past + 1):(start-2)]
    
    
    x <- cbind(intercept,CHI_l1,JPN_l1,GER_l1,USA_l1,CHI_l2,JPN_l2,GER_l2,USA_l2)   #説明変数行列
    beta_JPN <- solve(t(x) %*% x) %*% t(x) %*% JPN                 #varモデルは各方程式をOLS
    beta_GER <- solve(t(x) %*% x) %*% t(x) %*% GER                 #構造varのためそれぞれ計算
    beta_USA <- solve(t(x) %*% x) %*% t(x) %*% USA                 #*再帰的構造(CHI→JPN→GER→USA)を仮定する
    beta_CHI <- solve(t(x) %*% x) %*% t(x) %*% CHI
    #beta_JPN beta_GER beta_USA beta_CHI
    
    #beta_JPN  #OLS
    JPN_hat = x %*% beta_JPN
    error = y - JPN_hat
    
    #SUR(varモデル)の誤差項の共分散行列の推定(一致推定量not不偏)
    #再帰的構造を仮定
    CHI_res = CHI - x %*% beta_CHI
    JPN_res = JPN - x %*% beta_JPN 
    GER_res = GER - x %*% beta_GER
    USA_res = USA - x %*% beta_USA
    
    residual_covariance_matrix = (1/length(JPN)) * rbind(
      c( t(CHI_res) %*% CHI_res, t(CHI_res) %*% JPN_res, t(CHI_res) %*% GER_res, t(CHI_res) %*% USA_res),
      c( t(JPN_res) %*% CHI_res, t(JPN_res) %*% JPN_res, t(JPN_res) %*% GER_res, t(JPN_res) %*% USA_res),
      c( t(GER_res) %*% CHI_res, t(GER_res) %*% JPN_res, t(GER_res) %*% GER_res, t(GER_res) %*% USA_res),
      c( t(USA_res) %*% CHI_res, t(USA_res) %*% JPN_res, t(USA_res) %*% GER_res, t(USA_res) %*% USA_res)
    )
    
    #共分散行列の三角分解    Σ = ADA'なる下三角行列Aと対角行列Dを求める
    M <- residual_covariance_matrix        #(注意)三角分解する行列は対称行列
    d11 <- M[1,1]                          　#この三角分解は4×4用でadhocだが手計算で導出した
    a21 <- M[2,1] * (1/d11)                  # Aは対角成分が1に等しい下三角行列　要素をaijで表す
    a31 <- M[3,1] * (1/d11)                  # Dは対角行列で要素はdii
    a41 <- M[4,1] * (1/d11)
    d22 <- M[2,2] - a21^2 * d11
    a32 <- (M[2,3] - a21*a31*d11) * (1/d22)
    d33 <- M[3,3] - a31^2 * d11 - a32^2 * d22
    a42 <- (M[2,4] - a21*a41*d11) * (1/d22)
    a43 <- (M[3,4] - a31*a41*d11 - a32*a42*d22) * (1/d33)
    d44 <- M[4,4] - a41^2*d11 - a42^2*d22 - a43^2*d33
    
    A <- rbind( c(1,0,0,0), c(a21,1,0,0), c(a31,a32,1,0), c(a41,a42,a43,1))
    D <- rbind( c(d11,0,0,0), c(0,d22,0,0), c(0,0,d33,0), c(0,0,0,d44))
    A %*% D %*% t(A)                  #三角分解！ 対称行列Mと一致する事を検算済み
    # 確認用 M <- rbind( c(3,5,11,-3), c(5,2,0,-1), c(11,0,1,7), c(-3,-1,7,5))
    # 直交化撹乱項 u = A^(-1) * error  
    # 沖本p101 構造varの撹乱項と直交化撹乱項は再帰的構造の制約の元で一致
    # 三角分解は一意なのでA^(-1) = B なる同時点の変数間の関係を表すBが得られる
    B0 <- solve(A)
    coefficient_matrix <- rbind( t(beta_CHI), t(beta_JPN), t(beta_GER), t(beta_USA))
    coefficient_matrix    
    CONS <- coefficient_matrix[,1]
    B1 <- coefficient_matrix[,2:5]
    B2 <- coefficient_matrix[,6:9]
    
    # 構造varの係数行列の作成
    structural_var_coefficient_matrix <- cbind( B0 %*% CONS, B0 %*% B1, B0 %*% B2)
    structural_var_coefficient_matrix
    
    
    #varモデルでの予測 (1期先予測)
    beta <- beta_JPN
    beta
    predicted_y[i] <- 
      beta[1] + beta[2]*SSE_composite_index_1[start] + beta[3]*nikkei225_1[start] +
      beta[4]*dax_1[start] + beta[5]*S.P500_1[start] +
      beta[6]*SSE_composite_index_1[start-1] + beta[7]*nikkei225_1[start-1] +
      beta[8]*dax_1[start-1] + beta[9]*S.P500_1[start-1]
    predicted_y                    #start203時点のデータを使って1期先204時点を予測
    
    
    #構造varでの予測(1期先予測)
    B0[1:2,1:2]        #中国が日本の株にとっての外生と仮定しているので，今期に予測で使うmatrixは(中国,日本)の箇所のみ
    # 1本目y_t_china_hat = ... , 2本目y_t_japan_hat + alpha*y_t_china_hat
    betaC <- structural_var_coefficient_matrix[1,1:9]
    predicted_y_C <- 
      betaC[1] + betaC[2]*SSE_composite_index_1[start] + betaC[3]*nikkei225_1[start] +
      betaC[4]*dax_1[start] + betaC[5]*S.P500_1[start] +
      betaC[6]*SSE_composite_index_1[start-1] + betaC[7]*nikkei225_1[start-1] +
      betaC[8]*dax_1[start-1] + betaC[9]*S.P500_1[start-1]
    predicted_y_C
    
    betaJ <- structural_var_coefficient_matrix[2,1:9]
    predicted_y_J <-
      - (B0[2,1]*predicted_y_C) + betaJ[1] +          #中国外生の影響を今期も受ける
      betaJ[2]*SSE_composite_index_1[start] + betaJ[3]*nikkei225_1[start] +
      betaJ[4]*dax_1[start] + betaJ[5]*S.P500_1[start] +
      betaJ[6]*SSE_composite_index_1[start-1] + betaJ[7]*nikkei225_1[start-1] +
      betaJ[8]*dax_1[start-1] + betaJ[9]*S.P500_1[start-1]
    predicted_y_J
    
  #}
  return(predicted_y_J)
}


strvartrade <- function(istart,n,ep)    #short sell version
{                                         #istart=1の時,time=1,id=203,2015/1/27   n=100の時,time=100,2015/6/17    
  x <- nikkei225[203:(length(id)-1)]      #length(x)
  res <- rep(0,n)
  pos <- 0
  count <- 0
  plot.new()
  
  for(i in istart:n){
    
    if(istart + n > 101){
      count <- "error"
      period <- "error"
      break
    }
    else{period <- n - istart + 1}
    
    
    flg <- 0
    predicted_y <- strvar(i)                 #構造varで来期の収益率予測
    if( predicted_y > ep) {flg <- 1                             
                              count <- count + 1}    
    if( predicted_y < -ep) {flg <- -1
                               count <- count + 1}
    
    
    #if( ((x[i] - x[i-1]) / x[i-1]) >  ep) {flg <-  1}
    #if( ((x[i] - x[i-1]) / x[i-1]) < -ep) {flg <- -1}
    
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
  return(list(ret, count, period))
}

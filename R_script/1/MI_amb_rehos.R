#多重代入法
#救急車搬送数はhekit,再入院率はhekitかpooledOLS

library(MASS)#代入式の作成
options(scipen=16)

# /* ********************** 救急車搬送数補完 ************************** */

#補完用データの読み込み
rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/mroz/h18-h25panel_missing.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

#説明変数行列の作成(救急車)
g <- data4        #欠損しているデータ
x <- as.matrix(data.frame(g$nurse,g$ave_inpatient_per1day,g$ave_outpatient_per1day
                          ,g$medical_fee_per1inpatient,g$areas_facility
                          ,g$MrozDPC            #invMillsRatio
                          ))     #推定した係数順になっていることを確認
x <- cbind( rep(1,length(g$nurse)) ,x)
#head(x)
#x[1,]


#パラメタ
giji_n <- 20  #疑似データセット数

hokan_n <- length(g$nurse)      #補完するデータ数
#hist(rnorm(1000,mean=0,sd=sigma_hat))

k <- 7    #hekitの推定係数数
mk <- 1591  #データが全て得られているiの数(いまはh25-h18)
chi_df <- mk - k


#補完用行列の宣言
rm(predicted_amb)   #初期化
predicted_amb <- matrix(rep(0,length(g$nurse)*giji_n), nrow=length(g$nurse),ncol=giji_n)
head(predicted_amb)


#予測モデルの読み込み
data5 <- read.csv("/Users/serubantesu2/Downloads/hekit/kyu_metaana_coefs.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#head(data5)

beta <- coef_vector <- as.vector(data5[1:length(data5$X),length(data5$X)+2])
a_var <- V_matrix <- as.matrix(data5[1:length(data5$X),1:length(data5$X)+1])
sigma_hat2 <- (33.11803812)^2          #手入力(推定したものの単純平均)



#残差は毎回更新，係数は疑似セット毎  jはセット毎，iは病院毎
j <- 1    #初期疑似セット
for(j in 1:giji_n){
  
  #係数列作成 (stochastic regression imputation)
  g_b <- generated_beta <- mvrnorm(1, beta, a_var)   #係数の乱数
  generated_s <- ( sigma_hat2 * rchisq(hokan_n , df = chi_df) / chi_df )^(1/2)
  g_e <- giji_error <- generated_s * runif(hokan_n, min=0, max=1) #誤差項はサンプルごとに
                                                                    #random_uniform
  #補完値の作成
  for(i in 1:hokan_n){    #giji_n
    predicted_amb[i,j] <- x[i,] %*% g_b + g_e[i]
  }  
}

imputed_data <- data.frame(data4$total_id, predicted_amb)
write.csv(imputed_data, "imputed_amb.csv", quote=FALSE, row.names=FALSE)


X <- read.csv("/Users/serubantesu2/Downloads/hekit/imputed_amb.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
summary(X)

x2 <- subset(X$X10, X$X10 < -100)  #外れ値調べ


# /* ********************** 再入院率補完 hekit ************************** */

#補完用データの読み込み
rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/mroz/h18-h25panel_missing.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

#説明変数行列の作成(再入院率)
g <- data4        #欠損しているデータ
x <- as.matrix(data.frame(g$nurse,g$use_rates_general
                          ,g$medical_fee_per1outpatient,g$areas_facility
                          ,g$MrozDPC            #invMillsRatio
))     #推定した係数順になっていることを確認
x <- cbind( rep(1,length(g$nurse)) ,x)
#head(x)
#x[1,]


#パラメタ
giji_n <- 20  #疑似データセット数

hokan_n <- length(g$nurse)      #補完するデータ数
#hist(rnorm(1000,mean=0,sd=sigma_hat))

k <- 6    #hekitの推定係数数
mk <- 1591  #データが全て得られているiの数(いまはh25-h18)
chi_df <- mk - k


#補完用行列の宣言
rm(predicted_rehos)   #初期化
predicted_rehos <- matrix(rep(0,length(g$nurse)*giji_n), nrow=length(g$nurse),ncol=giji_n)
head(predicted_rehos)


#予測モデルの読み込み
data5 <- read.csv("/Users/serubantesu2/Downloads/hekit/rehos_metaana_coefs.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#head(data5)

beta <- coef_vector <- as.vector(data5[1:length(data5$X),length(data5$X)+2])
a_var <- V_matrix <- as.matrix(data5[1:length(data5$X),1:length(data5$X)+1])
sigma_hat2 <- (3.759527745)^2          #手入力(推定したものの単純平均)



#残差は毎回更新，係数は疑似セット毎  jはセット毎，iは病院毎
j <- 1    #初期疑似セット
for(j in 1:giji_n){
  
  #係数列作成 (stochastic regression imputation)
  g_b <- generated_beta <- mvrnorm(1, beta, a_var)   #係数の乱数
  generated_s <- ( sigma_hat2 * rchisq(hokan_n , df = chi_df) / chi_df )^(1/2)
  g_e <- giji_error <- generated_s * runif(hokan_n, min=0, max=1) #誤差項はサンプルごとに
  #random_uniform
  #補完値の作成
  for(i in 1:hokan_n){    #giji_n
    predicted_rehos[i,j] <- x[i,] %*% g_b + g_e[i]
  }  
}

imputed_data <- data.frame(data4$total_id, predicted_rehos)
write.csv(imputed_data, "imputed_rehos.csv", quote=FALSE, row.names=FALSE)



# /* ********************** 再入院率補完 pooled OLS ************************** */

#補完用データの読み込み
rm(list=ls())
data4 <- read.csv("/Users/serubantesu2/Downloads/hekit/mroz/h18-h25panel_missing.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 

#説明変数行列の作成(再入院率)
g <- data4        #欠損しているデータ
x <- as.matrix(data.frame(g$use_rates_general
                          ,g$ave_outpatient_per1day,g$ave_inpatient_per1day
                          ,g$medical_fee_per1outpatient,g$medical_fee_per1inpatient
))     #推定した係数順になっていることを確認
x <- cbind( rep(1,length(g$nurse)) ,x)
#head(x)
#x[1,]


#パラメタ
giji_n <- 20  #疑似データセット数

hokan_n <- length(g$nurse)      #補完するデータ数
#hist(rnorm(1000,mean=0,sd=sigma_hat))

k <- 6    #pooled_OLSの推定係数数
mk <- 1591  #データが全て得られているiの数(いまはh25-h18)
chi_df <- mk - k


#補完用行列の宣言
rm(predicted_rehos)   #初期化
predicted_rehos <- matrix(rep(0,length(g$nurse)*giji_n), nrow=length(g$nurse),ncol=giji_n)
head(predicted_rehos)


#予測モデルの読み込み
data5 <- read.csv("/Users/serubantesu2/Downloads/hekit/pred_rehos.csv",header= T,sep=",",na.strings=".",fileEncoding="cp932") 
#head(data5)

beta <- coef_vector <- as.vector(data5[1:length(data5$X),length(data5$X)+2])
a_var <- V_matrix <- as.matrix(data5[1:length(data5$X),1:length(data5$X)+1])
sigma_hat2 <- (3.674581)^2          #手入力(推定したもの)



#残差は毎回更新，係数は疑似セット毎  jはセット毎，iは病院毎
j <- 1    #初期疑似セット
for(j in 1:giji_n){
  
  #係数列作成 (stochastic regression imputation)
  g_b <- generated_beta <- mvrnorm(1, beta, a_var)   #係数の乱数
  generated_s <- ( sigma_hat2 * rchisq(hokan_n , df = chi_df) / chi_df )^(1/2)
  g_e <- giji_error <- generated_s * runif(hokan_n, min=0, max=1) #誤差項はサンプルごとに
  #random_uniform
  #補完値の作成
  for(i in 1:hokan_n){    #giji_n
    predicted_rehos[i,j] <- x[i,] %*% g_b + g_e[i]
  }  
}

summary(imputed_data)

imputed_data <- data.frame(data4$total_id, predicted_rehos)
write.csv(imputed_data, "imputed_rehos_ols.csv", quote=FALSE, row.names=FALSE)


x2 <- subset(predicted_rehos[,3], predicted_rehos[,3] > 50)  #外れ値調べ



# /* *********************************************** */ #
nurse <- data4$nurse[!is.na(data4$nurse)]
nurse
nurse2 <- nurse^2
nurse3 <- nurse^3
nurse4 <- nurse^4
nurse5 <- nurse^5
nurse6 <- nurse^6
nurse7 <- nurse^7

vcov_nurse <- data.frame(nurse, nurse2, nurse3, nurse4, nurse5, nurse6, nurse7)
cor(vcov_nurse)

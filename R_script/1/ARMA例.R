#AR(1)の分析

#データの生成
set.seed(10)
a <- rnorm(200)  #rnorm(n, mean=0, sd=1) 指定なしで標準正規乱数
x <- filter(a, 0.7, method = "recursive")  # y_t=ρ*y_{t-1}+u_t 〜AR(1)でfilter(誤差項,ρ,自己回帰)
x <- x[101:200]  #101〜200の標本を使う


#グラフとコレログラムを描く
plot(x)
acf(x)    #自己相関係数のコレログラム       　MA(q)はq+1以降ゼロ  (沖本p49)
pacf(x)   #偏自己相関係数〃　                AR(p)はp+1以降ゼロ MAは→AR(∞)なので減衰
ts.plot(x) #時系列プロット

#AR次数の選択
arx <- ar(x, method="mle")            #ar(データ,aic=TRUE(デフォルト),method=...)
arx
arx$aic   #aicの値

#モデルの次数を決定していた場合での係数の推定
arima(x, order = c(1,0,0),method = "CSS-ML",include.mean = FALSE)  
                  #arima(x,c(AR次数,階差,MA次数),CSSで初期値決め最尤法,定数項なし)


#かばん検定 下はLjung-Box検定
Box.test(arx$res, type= "Ljung")  #帰無仮説は残差の低次の自己相関係数が0




# ARMA(p,q)の分析
# AR(3,2)の例 y_t=φ_1*y_{t-1}+φ_2*y_{t-2}+φ_3*y_{t-3}+u_t+θ_1*u_{t-1}+θ_2*u_{t-2}

#データの生成
library(fArma)
set.seed(51)
y <- arima.sim(n=300,list(ar=c(0.7,-0.6,0.4),ma=c(0.8,0.4)))  #シミュφ1=0.7,θ1=0.8
y <- y[101:300]

#モデルの選択
library(forecast)
auto.arima(y)     #AIC基準により良いモデルを出力する

#次数を決定した場合のARMA係数の推定
fit32 <- armaFit(~ arma(3,2), include.mean=FALSE, data=y)     #armaモデル推定
par(mfrow = c(2,2), cex = 0.7)                            #グラフの領域指定(a×bの領域,倍率)
summary(fit32)

#AICの比較       
fit31 <- armaFit(~ arma(3,1), include.mean=FALSE, data=y)
fit22 <- armaFit(~ arma(2,2), include.mean=FALSE, data=y)
c(fit32@fit$aic, fit31@fit$aic, fit22@fit$aic)

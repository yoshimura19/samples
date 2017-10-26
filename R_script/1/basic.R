#行列編集
rm(x)
x <- rbind(c(1,2), 3:4, 5:6)
x[, 1]
x[1,2]
x[c(1,3), 2]
edit(x)
x2 <- edit(x)
x2
fix(x)
x

#リスト
x <- list(5:10, "abc", matrix(1:5), nrow=2, ncol=3)
x[[1]]
x[1]
x[[1]][3]

#データフレーム
rm(x)
x <- data.frame(SIZE=c("M","L","S","L","M"),SALES=c(1,2,1,3,1))
x
x[1,2]

data()
data(cars)
cars
str(cars)
summary(cars)
hist(cars$speed)
barplot(cars$speed)
plot(cars$speed, cars$dist)
cor(cars$speed, cars$dist)

a <- c(3,1,0,0,1,0,1,2,1,1,0,0,1,2,0,3,3,0,0,1)
shapiro.test(a)

ts(1:100, frequency=60)
ldeaths
print(ldeaths, calendar=FALSE)
ts.plot(ldeaths)
spectrum(ldeaths)
spec_result <- spectrum(ldeaths)
max_index <- which.max(spec_result$spec)
spec_result$freq[max_index]


source("kadai1lec.R")
rwcor()
rwcor2()
rwcor3()
summary(corre[])

library("xtable")
search()
library(help = "xtable")
?plot()
?exp()
x <- exp(log(5))+log(exp(4))       
x
ls()
ones <- rep(1,6)
ones
y <- seq(from = 2, to = 12, by = 2)
y
z <- 1:6
z
con <- c(y,z)
con
cvdata <- read.csv("/Users/serubantesu2/Downloads/cv.csv",row.names = 1)
cvdata
str(cvdata)
cvdata $pop
length(cvdata$pop)
cvdata3 <- cvdata[,c("pop","gpp","conv")]
cvdata3
length(cvdata3)
cvdata
X
prefecture <- cvdata[,c("X")]
prefecture
plot(conv ~ pop, data = cvdata)
result <- lm(conv ~ pop, data = cvdata)
summary(result)
abline(result)
??label
cvdata2 <- subset(cvdata, cvdata$pop > 3500)
cvdata2
text(cvdata2$pop,cvdata2$conv,rownames(cvdata),adj=1.15,cex=0.65,col="red")
result_2 <- lm(conv ~ pop + car + nm_f_30, data = cvdata)
cvdata $nm_f_30
summary(result_2)
cvdata$tohoku <- c(rep(1,7),numeric(40))
?rep
?numeric
cvdata$syutoken <- ifelse(
#  row.names(cvdata) == "Saitama-ken" |
#  row.names(cvdata) == "Chiba-ken" |
#  row.names(cvdata) == "Tokyo-to" |
  row.names(cvdata) == "Kanagawa-ken", 1,0)
cvdata$syutoken 
x <- row.names(cvdata) == "Tokyo-to"
cvdata$syutoken <- ifelse(row.names(cvdata) == "Tokyo-to"| "Chiba-ken"| 
                            "Saitama-ken" ,1,0)
cvdata$syutoken

library("AER")
data("CigarettesB")
data
Cigarette
plot(price ~ income,data=CigarettesB)
plot(packs ~ price,data=CigarettesB)
plot(packs ~ income, data = CigarettesB)
OLS <- lm(packs ~ price + income, data = CigarettesB)
summary(OLS)
abline(OLS)
plot(CigarettesB$income, OLS$res)
library("lmtest")  #Breusch-Pagan test
bptest(OLS, varformula = ~income + I(income^2) , data = CigarettesB, student = FALSE)
bptest(OLS, varformula = ~income + price , data = CigarettesB, student = FALSE)
bptest(OLS, ~income *price + I(income^2) + I(price^2),data = CigarettesB)

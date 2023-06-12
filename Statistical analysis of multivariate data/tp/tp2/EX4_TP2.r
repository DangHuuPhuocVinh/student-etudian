EX4<-read.csv(file.choose())
mydata <-data.frame(EX4)

##Q1
droite_X1 <- lm(Y~X_1, data=mydata)
coef(droite_X1)
qt(1-0.05/2,20)
summary(droite_X1) 
#Tobs = 2.379 > 2.085963 => rejetter H0

##Q2
#Y_chapeau = B0_chapeau + B1_chapeau*X1 + B2_chapeau*X2
droite_X1X2<- lm(Y~X_1+X_2, data=mydata)
coef(droite_X1X2) 
#b0_chapeau = 35.55464170
#B1_chapeau = 0.07895034
#B2_chapeau = 0.47072920
#=>Y_chapeau = 35.55464170 + 0.07895034*X1 + 0.47072920*X2

##Q3
anova(droite_X1X2)
MCreg = (1727.2+148.9)/2
Fobs = MCreg / 313.28 
qf(0.95,2,19)
#=> Fobs > 3.521893 => rejetter H0

##Q4
summary(droite_X1X2) 
#R^2= 0.2397, cette equation a significative ameliorer l'estimation

##Q5
droite<-lm(Y~X_1+X_2+X_3, data=mydata)
coef(droite) 
#Y_chapeau = 23.999566149 - 0.006173447*X1 - 0.479869473*X2 + 8.483500169*X3

##Q6
confint(droite)[4,] 
#pour beta3: [0.402924, 16.5640763]

##Q7
predict(droite, list(X_1 = 221, X_2 = 39, X_3 = 7), interval = "confidence", level = 0.95)

##Q8
summary(droite) 
#R^2= 0.4014, cette equation a significative ameliorer l'estimation

##Q9
droiteX1_X2X3<-lm(X_1~X_2+X_3, data = mydata)
coef(droiteX1_X2X3)

##Q10
droiteX1_X3<-lm(X_1~X_3, data = mydata)
cor.test(mydata$X_3,mydata$X_1)
#L'intervalle de confiance a 95% : [0.5754128 ; 0.9145856]

setwd("D://PPThongKeData")
X<-c(4.0,5.7,4.9,3.0,14.8,69.6,63.8,26.2,38.3,24.7,67.5)
Y=c(3432,3273,3049,3642,3394,2628,2204,2643,2192,2687,2159)
EX7BIS<-data.frame(X=X,YY=log(Y))

###Q1
plot(EX7BIS)

###Q2
droite7<-lm(YY~X,data=EX7BIS)
coef(droite7)
###Q3
anova(droite7)

# SCreg:  0.26353   1   0.26353
# SCres:  0.10949   9   0.012166
# totale: 0.37302   10    
# F    :  21.661

###Q4
confint(droite7, level = 0.95)

###Q5
reg <- lm(Y ~ X)
new <- data.frame(X = seq(0, 100, 5))
pred.w.clim <- predict(reg, new, interval="confidence", level = 0.95)

resc <- cbind(pred.w.clim, new)
plot(Y ~ X, pch=16)

lines(resc$fit ~ resc$X)
lines(resc$lwr ~ resc$X, col=2)
lines(resc$upr ~ resc$X, col=2)




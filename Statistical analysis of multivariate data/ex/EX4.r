setwd("D://PPThongKeData")

Xi<-c(7,9,9,10,13,17,19,20,21,25)
Yi=c(5,4,6,4,1,2,0,1,1,0)
###Q1
droite4<-lm(Yi~Xi)
coef(droite4)
###Q2
predict(droite4,interval = "confidence", level = 0.99)

###Q3
#E(Yi|X=10)
predict(droite4, list(Xi=10))
#Var(Yi|X=10)

###Q4
sum_Yi = sum(Yi)
sum_Y_chapeau = sum(fitted(droite4))


###Q5
EX4<-data.frame(Xi,Yi)
t.test(EX4)

###Q6

reg <- lm(Yi ~ Xi)
new <- data.frame(Xi = seq(0, 30, 5))
pred.w.clim <- predict(reg, new, interval="confidence", level = 0.95)

resc <- cbind(pred.w.clim, new)
plot(Yi ~ Xi, pch=16)

lines(resc$fit ~ resc$X)
lines(resc$lwr ~ resc$X, col=2)
lines(resc$upr ~ resc$X, col=2)


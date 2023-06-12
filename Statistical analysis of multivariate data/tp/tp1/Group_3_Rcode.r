#======================Exercice 4==================
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

#======================Exercice 5==================

Y=c(10,18,24,22,27,13,10,24,25,8,16,20,28,22,19,18,26,14,20,26,30,12)
X<-c(3,7,10,9,11,6,5,8,7,4,6,9,12,8,10,9,11,6,8,10,12,5)

###Q1: Y est cout direct, X est nombre de mois

###Q2
plot(X,Y) #Non, parce que plusieurs le cout direct pour une meme valeur de nombre de mois

###Q3
droite5<-lm(Y~X)
coef(droite5) ##->Yi = 1.549407 + 2.260870Xi
fitted(droite5)

###Q4
predict(droite5, list(X=6))

###Q5 : 
EX5<-data.frame(X,Y)
y_bar = mean(Y)
y_bar

###Q6
anova(droite5)
SCtotal = 705.39 + 159.70

###Q7
fitted(droite5)

###Q8
resid(droite5)

###Q9
summary(droite5) #R^2 = 0.8154. Plus coefficient de determination est proche de 1, les donnees sont alignees sur la droite de regression.

#======================Exercice 6==================

X<-c(1.73, 1.73, 1.83, 1.84, 1.84, 1.78, 1.84, 1.85, 1.85, 1.86, 1.85, 1.91, 1.87, 1.96, 1.88, 1.94, 1.85, 2.00, 1.94, 2.01)
Y=c(2.32, 2.31, 2.40, 2.40, 2.40, 2.33, 2.37, 2.37, 2.37, 2.37, 2.36, 2.41, 2.36, 2.45, 2.36, 2.39, 2.28, 2.42, 2.35, 2.40)
###Q1
droite6<-lm(Y~X)
coef(droite6)
fitted(droite6)
resid(droite6)
###Q2
anova(droite6)
SCtotal = 0.012823 + 0.018158
# SCreg:  0.012823    1     0.012823
# SCres:  0.018158    18    0.02118333
# totale: 0.030981    19  
# F    :  12.71142

###Q3
summary(droite6) #ce pourcentage est de 41.39%


#======================Exercice 7==================

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


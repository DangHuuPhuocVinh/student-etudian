Yi = c(37.8, 22.5, 17.1, 10.8, 7.2, 42.3, 30.2, 19.4, 14.8, 9.5, 32.4,21.6)
X1 <- c(4,4,3,2,1,6,4,4,1,1,3,4)
X2 <- c(4.0,3.6,3.1,3.2,3.0,3.8,3.8,2.9,3.8,2.8,3.4,2.8)

droite_X1<-lm(Yi~X1)
droite_X2<-lm(Yi~X2)
droite<-lm(Yi~X1+X2)

###Q1
summary(droite_X1) #Y en fonction X1 - pourcentage: 69.03 %
summary(droite_X2)#Y en fonction X2 - pourcentage: 45.3 %
summary(droite) #Y en fonction X1+X2 - pourcentage: 84.81 %
 
##Q2
anova(droite_X1)
summary(droite_X1)
#CMres = 44.00
#s = 6.633
#Regression due a X1:     440.03/(12-2)   sqrt((440.03)/(12-2))

anova(droite_X2)
summary(droite_X2)
#CMres = 77.71 
#s = 8.815
#Regression due a X2:     777.10/(12-2)   sqrt((777.10)/(12-2))

anova(droite)
summary(droite)
#s = 4.897
#CMres = 23.98
#Regression due a X1,X2:  215.81/(12-3)   sqrt((215.81)/(12-3))

##Q3
anova(droite)
summary(droite)
#Regression due a X1,X2:  1204.86   2   602.43   25.12335
#Residuelle            :  215.81    9   23.97889
#Totale                :  1420.67   11

##Q4
summary(droite)
qf(0.95,2,9)

#H0: beta1 = beta2 = 0
#On a Fobs = 25.12335 > 4.256495 => rejetter H0

##Q5: intervalle de confiance pour beta1
summary(droite_X1)
confint(droite_X1)[2,]

#B0 : [-6.242858; 13.28806]
#B1 : [3.187036 ; 8.88479 ]
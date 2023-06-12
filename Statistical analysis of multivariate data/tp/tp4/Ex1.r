
EX1<-read.csv(file.choose())
Y<-EX1$FUEL.x_i5
X1<-EX1$TAX.x_i1
X2<-EX1$DLIC.x_i2
X3<-EX1$INC.x_i13
X4<-EX1$ROAD.x_i4

##Exercice1
##Q1
reg1<-lm(log(Y)~X1+X2+X3+X4)
step(reg1) #vi co AIC nho nhat

##Q2
##Etape1:
cor(Y,X1)
cor(Y,X2)
cor(Y,X3)
cor(Y,X4) 
regX2<-lm(log(Y)~X2)
regX2
#chon modele y_chaupeau = 5.00690 + 0.02338X2 vi co cor(Y,X2) = 0.6989

#Etape2:
regresX2<-resid(regX2)
cor(regresX2,X1)
cor(regresX2,X3)
cor(regresX2,X4)
regX2X3<-lm(log(Y)~X2+X3)
regX2X3
#chon modele y_chapeau = 5.47906 + 0.02569X1 - 0.14241X2 vi co cor(regres2,X3) = -0.59

#Etape3:
regresX2X3<-resid(regX2X3)
cor(regresX2X3,X1)
cor(regresX2X3,X4)
regX1X2X3<-lm(log(Y)~X1+X2+X3)
regX1X2X3
#chon modele y_chapeau = 5.97173 - 0.04850X1 + 0.02322X2 - 0.13764X3 vi co cor(regresX2X3,X1) = -0.3911 

#Etape4:
regresX1X2X3<-resid(regX1X2X3)
cor(regresX1X2X3,X4) #khong chon vi cor(regresX1X2X3,X4) = -0.07419771 < 15%

#vi vay chon mo hinh: y_chapeau = 5.97173 - 0.04850X1 + 0.02322X2 - 0.13764X3

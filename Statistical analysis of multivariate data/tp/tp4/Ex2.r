
EX2<-read.csv(file.choose())
Y<-EX2$Azote
X1<-EX2$Agriculture
X2<-EX2$Forêts
X3<-EX2$Habitations
X4<-EX2$Com..et.ind.

##Exercice1
##Q1
library(leaps)

recherche.ex<-regsubsets(Y~X1+X2+X3+X4,int=T,nbest=1,
                          nvmax=10,method="exhaustive",really.big=T, data=EX2)
res_summary <-summary(recherche.ex)
res_summary
res_summary$cp #Mallows' Cp
#chon modele y = beta0 + beta1X1 + beta2X2 + beta4X4 + epsilon vi co Cp = 3.045 gan bang voi p = 4, khong ap dung mo hinh day du
##Q2

step(lm(Y~X1+X2+X3+X4))


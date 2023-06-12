#I
I_Ex <- read.csv(file.choose())
I_Ex
library(leaps)

recherche.ex<-regsubsets(num_of_book~age+num_of_place+form+month+duration+total+salary,int=T,nbest=1,
                          nvmax=10,method="exhaustive",really.big=T,data=I_Ex)
res_summary <-summary(recherche.ex)

plot(recherche.ex,scale="adjr2")

res_summary$adjr2

max.adjr2 <- which.max(res_summary$adjr2)
max.adjr2 
names(which(res_summary$which[max.adjr2,]==TRUE))

result1<-lm(num_of_book~age+num_of_place+month+duration+total, data = I_Ex)
coef(result1)
summary(result1)
anova(result1)

par(mfrow =c(2,2))
plot(res_summary$adjr2,xlab="Number of Variables ",ylab="Adjusted RSq",type="l")
points(max.adjr2,res_summary$adjr2[max.adjr2],col ="red",cex =2, pch =20)

#############################
#II
#Ex1
#a/
setwd("C:\Users\Vinh\Desktop\bt\donnees\ozone.csv")
II_Ex1 <- read.csv(file.choose())
II_Ex1
recherche.ex1_2 <- lm(maxO3 ~ T9 + T12 + Ne12 + Ne15 + Vx12 + maxO3v, data = II_Ex1)
#avec 1 variable
reg1 <- lm(maxO3 ~ T9, data = II_Ex1)
summary(reg1)# tobs = 10.263

reg2 <- lm(maxO3 ~ T12, data = II_Ex1)
summary(reg2)# tobs = 13.258 #choisir

reg3 <- lm(maxO3 ~ Ne12, data = II_Ex1)
summary(reg5)# tobs = -8.753

reg4 <- lm(maxO3 ~ Ne15, data = II_Ex1)
summary(reg6)# tobs = -5.712

reg5 <- lm(maxO3 ~ Vx12, data = II_Ex1)
summary(reg8)# tobs = 5.007

reg6 <- lm(maxO3 ~ maxO3v, data = II_Ex1)
summary(reg10)# tobs = 9.848

####
#avec 2 variables
reg21 <- lm(maxO3 ~ T12 + T9, data = II_Ex1)
summary(reg21)# tobs = 0.248

reg23 <- lm(maxO3 ~ T12 + Ne12, data = II_Ex1)
summary(reg23)# tobs = -2.858

reg24 <- lm(maxO3 ~ T12 + Ne15, data = II_Ex1)
summary(reg24)# tobs = -2.308

reg25 <- lm(maxO3 ~ T12 + Vx12, data = II_Ex1)
summary(reg25)#tobs = 3.465

reg26 <- lm(maxO3 ~ T12 + maxO3v, data = II_Ex1)
summary(reg26)#tobs = 5.607 # choisir

####
#avec 3 variables
reg261 <- lm(maxO3 ~ T12 + maxO3v + T9, data = II_Ex1)
summary(reg261)# tobs = -0.965

reg263 <- lm(maxO3 ~ T12 + maxO3v + Ne12, data = II_Ex1)
summary(reg263)# tobs = -3.371

reg264 <- lm(maxO3 ~ T12 + maxO3v + Ne15, data = II_Ex1)
summary(reg264)# tobs = -2.218

reg265 <- lm(maxO3 ~ T12 + maxO3v + Vx12, data = II_Ex1)
summary(reg265)# tobs = 3.579 #choisir

####
#avec 4 variables
reg2651 <- lm(maxO3 ~ T12 + maxO3v + Vx12 + T9, data = II_Ex1)
summary(reg2651)# tobs = -0.529

reg2653 <- lm(maxO3 ~ T12 + maxO3v + Vx12 + Ne12, data = II_Ex1)
summary(reg2653)# tobs = -2.090 #choisir

reg2654 <- lm(maxO3 ~ T12 + maxO3v + Vx12 + Ne15, data = II_Ex1)
summary(reg2654)# tobs = -1.150

####
reg26531 <- lm(maxO3 ~ T12 + maxO3v + Vx12 + Ne12 + T9, data = II_Ex1)
summary(reg26531)# tobs = 0.069 et p-value = 0.94537

reg26534 <- lm(maxO3 ~ T12 + maxO3v + Vx12 + Ne12 + Ne15, data = II_Ex1)
summary(reg26534)# tobs = -0.020 et p-value = 0.9844

####
#Meilleur modele
reg2653 <- lm(maxO3 ~ T12 + maxO3v + Vx12 + Ne12, data = II_Ex1)
coef(reg2653)

step(recherche.ex1_2)

#####
#faire plus
#j'essaye calcule stepwise etape par etape avec 10 variables dans le fichier
reg1 <- lm(maxO3 ~ T9, data = II_Ex1)
summary(reg1)# tobs = 10.263

reg2 <- lm(maxO3 ~ T12, data = II_Ex1)
summary(reg2)# tobs = 13.258

reg3 <- lm(maxO3 ~ T15, data = II_Ex1)
summary(reg3)# tobs = 12.844

reg4 <- lm(maxO3 ~ Ne9, data = II_Ex1)
summary(reg4)# tobs = -8.325

reg5 <- lm(maxO3 ~ Ne12, data = II_Ex1)
summary(reg5)# tobs = -8.753

reg6 <- lm(maxO3 ~ Ne15, data = II_Ex1)
summary(reg6)# tobs = -5.712

reg7 <- lm(maxO3 ~ Vx9, data = II_Ex1)
summary(reg7)# tobs = 6.514

reg8 <- lm(maxO3 ~ Vx12, data = II_Ex1)
summary(reg8)# tobs = 5.007

reg9 <- lm(maxO3 ~ Vx15, data = II_Ex1)
summary(reg9)# tobs = 4.468

reg10 <- lm(maxO3 ~ maxO3v, data = II_Ex1)
summary(reg10)# tobs = 9.848

####
reg21 <- lm(maxO3 ~ T12 + T9, data = II_Ex1)
summary(reg21)# tobs = 0.248

reg23 <- lm(maxO3 ~ T12 + T15, data = II_Ex1)
summary(reg23)# tobs = 1.713

reg24 <- lm(maxO3 ~ T12 + Ne9, data = II_Ex1)
summary(reg24)# tobs = -3.584

reg25 <- lm(maxO3 ~ T12 + Ne12, data = II_Ex1)
summary(reg25)#tobs = -2.858

reg26 <- lm(maxO3 ~ T12 + Ne15, data = II_Ex1)
summary(reg26)# tobs = -2.308

reg27 <- lm(maxO3 ~ T12 + Vx9, data = II_Ex1)
summary(reg27)# tobs = 3.772

reg28 <- lm(maxO3 ~ T12 + Vx12, data = II_Ex1)
summary(reg28)# tobs = 3.465

reg29 <- lm(maxO3 ~ T12 + Vx15, data = II_Ex1)
summary(reg29)# tobs = 3.292

reg210 <- lm(maxO3 ~ T12 + maxO3v, data = II_Ex1)
summary(reg210)# tobs = 5.607
####

reg2101 <- lm(maxO3 ~ T12 + maxO3v + T9, data = II_Ex1)
summary(reg2101)# tobs = -0.965

reg2103 <- lm(maxO3 ~ T12 + maxO3v + T15, data = II_Ex1)
summary(reg2103)# tobs = 1.206

reg2104 <- lm(maxO3 ~ T12 + maxO3v + Ne9, data = II_Ex1)
summary(reg2104)# tobs = -4.700

reg2105 <- lm(maxO3 ~ T12 + maxO3v + Ne12, data = II_Ex1)
summary(reg2105)# tobs = -3.371

reg2106 <- lm(maxO3 ~ T12 + maxO3v + Ne15, data = II_Ex1)
summary(reg2106)# tobs = -2.218

reg2107 <- lm(maxO3 ~ T12 + maxO3v + Vx9, data = II_Ex1)
summary(reg2107)# tobs = 3.485

reg2108 <- lm(maxO3 ~ T12 + maxO3v + Vx12, data = II_Ex1)
summary(reg2108)# tobs = 3.579

reg2109 <- lm(maxO3 ~ T12 + maxO3v + Vx15, data = II_Ex1)
summary(reg2109)# tobs = 3.467
####

reg21041 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + T9, data = II_Ex1)
summary(reg21041)# tobs = -0.731

reg21043 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + T15, data = II_Ex1)
summary(reg21043)# tobs = 0.667

reg21045 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Ne12, data = II_Ex1)
summary(reg21045)# tobs = -0.545

reg21046 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Ne15, data = II_Ex1)
summary(reg21046)# tobs = -0.548

reg21047 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9, data = II_Ex1)
summary(reg21047)# tobs = 2.147

reg21048 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx12, data = II_Ex1)
summary(reg21048)# tobs = 1.782

reg21049 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx15, data = II_Ex1)
summary(reg21049)# tobs = 1.753
####
reg210471 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9 + T9, data = II_Ex1)
summary(reg210471)

reg210473 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9 + T15, data = II_Ex1)
summary(reg210473)

reg210475 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9 + Ne12, data = II_Ex1)
summary(reg210475)

reg210476 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9 + Ne15, data = II_Ex1)
summary(reg210476)

reg210478 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9 + Vx12, data = II_Ex1)
summary(reg210478)

reg210479 <- lm(maxO3 ~ T12 + maxO3v + Ne9 + Vx9 + Vx15, data = II_Ex1)
summary(reg210479)

#La meilleur modele avoir des variables T12, Ne9, Vx9, maxo3v

#####
#b/stagewise
cor(II_Ex1$maxO3,II_Ex1$maxO3v)
cor(II_Ex1$maxO3,II_Ex1$T9)
cor(II_Ex1$maxO3,II_Ex1$T12)#choisir
cor(II_Ex1$maxO3,II_Ex1$Vx12)
cor(II_Ex1$maxO3,II_Ex1$Ne12)
cor(II_Ex1$maxO3,II_Ex1$Ne15)

regT12 <- lm(maxO3 ~ T12, data=II_Ex1)
res1<-residuals(regT12)

cor(res1,II_Ex1$maxO3v)#choisir
cor(res1,II_Ex1$T9)
cor(res1,II_Ex1$Vx12)
cor(res1,II_Ex1$Ne12)
cor(res1,II_Ex1$Ne15)

regmaxO3v <- lm(res1 ~ II_Ex1$maxO3v)
res2<-residuals(regmaxO3v)

cor(res2,II_Ex1$T9)#choisir
cor(res2,II_Ex1$Vx12)
cor(res2,II_Ex1$Ne12)
cor(res2,II_Ex1$Ne15)

regT9 <- lm(res2 ~ II_Ex1$T9)
res3<-residuals(regT9)

cor(res3,II_Ex1$Vx12)#choisir
cor(res3,II_Ex1$Ne12)
cor(res3,II_Ex1$Ne15)

regVx12 <- lm(res3 ~ II_Ex1$Vx12)
res4<-residuals(regVx12)

cor(res4,II_Ex1$Ne12)
cor(res4,II_Ex1$Ne15)

##Meilleur modèle
regT12 <- lm(maxO3 ~ T12, data=II_Ex1)
regmaxO3v <- lm(res1 ~ II_Ex1$maxO3v)
regT9 <- lm(res2 ~ II_Ex1$T9)
regVx12 <- lm(res3 ~ II_Ex1$Vx12)

result2 <- lm(maxO3 ~ T12 + maxO3v + T9 + Vx12, data = II_Ex1)
coef(result2)
##############################
#Ex2
setwd("C:\Users\Vinh\Desktop\bt\donnees\tauxaccidents.csv")
II_Ex2 <- read.csv(file.choose())
II_Ex2
library(leaps)
#J'ai change des variables du format x_i,numero au format x_inumero parce que
#le R ne reconnais pas le format dernier dans le fichier tauxaccidents.csv
#Exemple: x_i,1 -> x_i1

recherche.ex2<-regsubsets(y_i~x_i1+x_i2+x_i3+x_i4+x_i5+x_i6+x_i7+x_i8+x_i9+x_i10+x_i11+x_i12+x_i13,int=T,nbest=1,
                         nvmax=10,method="exhaustive",really.big=T,data=II_Ex2)
res_summary <-summary(recherche.ex2)

plot(recherche.ex2,scale="adjr2")

res_summary$adjr2

max.adjr2 <- which.max(res_summary$adjr2)
max.adjr2 
names(which(res_summary$which[max.adjr2,]==TRUE))

#essayer avec step()
try<-lm(y_i~x_i1+x_i2+x_i3+x_i4+x_i5+x_i6+x_i7+x_i8+x_i9+x_i10+x_i11+x_i12+x_i13, data = II_Ex2)
step(try)

par(mfrow =c(2,2))
plot(res_summary$adjr2,xlab="Number of Variables ",ylab="Adjusted RSq",type="l")
points(max.adjr2,res_summary$adjr2[max.adjr2],col ="red",cex =2, pch =20)

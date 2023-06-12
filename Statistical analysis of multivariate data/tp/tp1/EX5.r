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
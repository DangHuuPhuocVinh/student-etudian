setwd("~/Users/sv/Downloads/Donnees_TP_Choixdumodele/TD3_Ex1")
TD3_Ex1 <- read.csv(file.choose())
TD3_Ex1

library(leaps)

recherche.Ex1 <- regsubsets(FUEL.x_i5~TAX.x_i1 + DLIC.x_i2 + INC.x_i13 + ROAD.x_i4, int=T, nbest =1,
                            nvmax = 10, method ="exhaustive", really.big=T,data=TD3_Ex1)
res_sumary <- summary(recherche.Ex1)
resume <- summary(res_sumary)
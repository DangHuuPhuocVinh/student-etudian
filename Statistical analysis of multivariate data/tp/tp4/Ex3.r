
EX3<-read.csv(file.choose())

reg<-lm(EX3$y_i~., data=EX3)
step(reg)


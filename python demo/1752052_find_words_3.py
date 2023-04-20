# -*- coding: utf-8 -*-
"""
Created on Wed Dec 11 21:55:24 2019

@author: Vinh
"""

fname1 = input("Enter the name of the file 1:")
fname2 = input("Enter the name of the file 2:")

#array 1
file=open(fname1,"r+", encoding="utf-8-sig")#can read to unicode

arr1 = []
wordcount={}
quan1 = []

for word in file.read().split(): 
    if word not in wordcount:
        wordcount[word] = 1
    else:
        wordcount[word] += 1

for k,v in wordcount.items():
    arr1.append(k)
    quan1.append(v) #quantity
    
file.close();


#array 2
file=open(fname2,"r+", encoding="utf-8-sig")

arr2 = []
quan2 = []
wordcount={}

for word in file.read().split(): 
    if word not in wordcount:
        wordcount[word] = 1
    else:
        wordcount[word] += 1

for k,v in wordcount.items():
    arr2.append(k)
    quan2.append(v) 
    
file.close();

print("\n")
print("Les mots differants de arr1: ", arr1)
print("Les mots differants de arr2: ", arr2)

#compare array 

commun = []
quan = []

for i in range(len(arr1)):
    for j in range(len(arr2)):
        if(arr1[i] == arr2[j]):
            commun.append(arr1[i])
            quan.append(quan1[i] + quan2[j])
            
print("\n")
#1a
print("The same words from 2 document: ", commun)

#2a
print("\n")
for i in range(len(commun)):    
    print("Quantity of words: ", commun[i], quan[i])


#3a
max = quan[0]
min = quan[0]
P_max = 0 
P_min = 0

for i in range(1, len(quan)):
    if (quan[i] > max):
        max = quan[i]
        P_max = i
    
    if (quan[i] < min):
        min = quan[i]
        P_min = i

print("\n")
print("Le mot avec le nombre d'apparence max:", commun[P_max])
print("Le mot avec le nombre d'apparence min:", commun[P_min])

# -*- coding: utf-8 -*-
"""
Created on Thu Dec 12 15:05:31 2019

@author: Vinh
"""

n = 50
number = 0

while (True):
    print("Is your number is less or bigger than ", n)
    print("1 : less")
    print("2 : bigger")
    print("0 : equal")

    awn = int(input("Your answer : "))
    number = awn
    
    
    if(number == 2):
        temp = n
        n = n // 2 + temp
    
    
    if(number == 1):
        n = n // 2
             
    if(number == 0):
        break
        
print ("RESULT: ", n)   
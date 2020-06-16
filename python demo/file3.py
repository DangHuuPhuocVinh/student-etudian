# -*- coding: utf-8 -*-
"""
Created on Thu Dec  5 14:41:04 2019

@author: Vinh
"""

with open("f1.txt") as f1,open("vanhocvn.txt") as f2:
    words=set(line.strip() for line in f2)   
    for line in f2:
        word,freq = line.split()
        if word in words:        
            print (words)
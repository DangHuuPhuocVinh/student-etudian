# -*- coding: utf-8 -*-
"""
Created on Thu Nov  7 15:21:00 2019

@author: Vinh
"""

Tour1 = "Tour 1"
Tour2 = "Tour 2"
Tour3 = "Tour 3"

def TourdeHanoi(numDisk, Tour1, Tour2, Tour3):

    if numDisk == 1:
        print ("Move", Tour1, "to", Tour3)
    else:
        TourdeHanoi(numDisk-1, Tour1, Tour3, Tour2)
        print ("Move", Tour1, "to", Tour3)
        TourdeHanoi(numDisk-1, Tour2, Tour1, Tour3)


n = float(input("Input number of Disk: "))
TourdeHanoi(n, Tour1, Tour2, Tour3)
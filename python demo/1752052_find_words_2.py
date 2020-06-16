# -*- coding: utf-8 -*-
"""
Created on Thu Nov 21 16:01:40 2019

@author: Vinh
"""

fname = input("Enter the name of the file:")
infile = open(fname, 'r')
lines = 0
words = 0
characters = 0
for line in infile:
    wordslist = line.split()
    lines = lines + 1
    words = words + len(wordslist)
    characters = characters + len(line)
print('lines: ',lines)
print('words: ',words)
print('characters: ',characters)
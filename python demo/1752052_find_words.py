# -*- coding: utf-8 -*-
"""
Created on Thu Nov 21 14:53:12 2019

@author: Vinh
"""
"""f=open("van.txt","r")
if f.mode == 'r':
    contents = f.read()
    print(contents)"""

def count_word(file):

    #open an input and output file
    
    infile = open(file,"r")
    outfile = open("file.txt","w")
    
    #count words in string
    split_string = infile.read().split()
    string_dict = {}
    
    #first populate the dictionary with the keys being each word in the string, all having zero for their values.
    for word in split_string:
        string_dict[word] = 0

    #Then cycle through the split string again and if the word is one of the keys in the dictionary add 1 each time.
    for word in split_string:
        if word in string_dict.keys():
            string_dict[word]=string_dict[word]+1

    outfile.write(str(string_dict))
    
    outfile.close()
    infile.close()


name_infile_1 = input("Enter the name of a text file: ")
count_word(name_infile_1)
print ("file.txt was created successfully")

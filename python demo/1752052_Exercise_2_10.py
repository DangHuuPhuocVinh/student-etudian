# -*- coding: utf-8 -*-
# Author: Mai Trọng Nhân [MSSV] 1752039

import sys
import function as func

m = int(input("Nhập số dòng: "))
n = int(input("Nhập số cột: "))

arr_A = []
arr_B = []

func.inputArray(arr_A, n, m)
print('Mảng A vừa nhập là: ')
func.outputArray(arr_A, n, m)

func.inputArray(arr_B, n, m)
print('Mảng B vừa nhập là: ')
func.outputArray(arr_B, n, m)

for i in range(0, n):
    for j in range(0, m):
        if(arr_A[i][j] == arr_B[i][j]):
            arr_A[i][j] = arr_B[i][j] = 0

print('=======================================')
print('Mảng A và B sau khi thay thế các phần tử trùng bằng 0:')
print('Mảng A: ')
func.outputArray(arr_A, n, m)
print('Mảng B: ')
func.outputArray(arr_B, n, m)
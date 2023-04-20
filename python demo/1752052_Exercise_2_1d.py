# -*- coding: utf-8 -*-
# Author: Mai Trọng Nhân [MSSV] 1752039

import sys
import function as func


n = int(input("Nhập số dòng và số cột: "))

arr = []

func.inputArray(arr, n, n)
func.outputArray(arr, n, n)

temp = 0
for i in range(0, n):
    for j in range(0, n):
        if(int(arr[i][j]) > 0):
            temp += int(arr[i][j])

print("Tổng các phần tử không âm của mảng là: ", temp)


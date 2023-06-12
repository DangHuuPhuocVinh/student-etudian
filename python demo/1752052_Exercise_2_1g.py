# -*- coding: utf-8 -*-

import sys
import function as func


n = int(input("Nhập số dòng và số cột: "))

arr = []

func.inputArray(arr, n, n)
func.outputArray(arr, n, n)

def sum_Element(arr, n):
    count = 0
    for i in range(0, n):
        count += int(arr[i][n - 1 -i])
    return count

print('Tổng các phần tử trên đường chéo phụ của mảng là: ', sum_Element(arr, n))

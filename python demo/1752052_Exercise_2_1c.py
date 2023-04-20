# -*- coding: utf-8 -*-

import sys
import function as func
from pip._vendor.msgpack.fallback import xrange

n = int(input("Nhập số dòng và số cột: "))

arr = []

func.inputArray(arr, n, n)
func.outputArray(arr, n, n)

# hàm kiểm tra số nguyên tố
def isPrime(number):
    count = 2
    while True:
        if number == 1:
            return  0

        number_check = number % count
        if count == number:
            return 1

        if number_check == 0:
            return 0
        else:
            count = count + 1
            continue

count = 0
for i in range(0, n):
    for j in range(0, n):
        if(isPrime(arr[i][j]) == 1):
            count += 1

print("Số lần xuất hiện của các số nguyên tố trong mảng là: ", count)

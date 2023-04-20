# -*- coding: utf-8 -*-



import function as func


n = int(input("Nhập số dòng và số cột: "))

arr = []

func.inputArray(arr, n, n)
func.outputArray(arr, n, n)

temp = int(input("Nhập phần tử muốn đếm số lần xuất hiện: "))

count = 0
for i in range(0, n):
    for j in range(0, n):
        if(temp == int(arr[i][j])):
            count += 1

print("Số lần xuất hiện của %d là: " % temp, count)


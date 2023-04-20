# -*- coding: utf-8 -*-
# Author: Mai Trọng Nhân [MSSV] 1752039

import sys

def inputArray(a, m, n):
    for i in range(0, m):
        a.append([])
        for j in range(0, n):
            x = float(input("Nhập phần tử thứ a[%d][%d]: " % (i+1, j+1)))
            a[i].append(x)

def outputArray(a, m, n):
    for i in range(0, m):
        for j in range(0, n):
            print("%3d " % a[i][j], end='')
        print()

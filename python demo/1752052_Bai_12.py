# -*- coding: utf-8 -*-

import random
#n = int (input())
#x = random.sample(range(1000000), n)
#print(x)

n = int(input("Nhập n: "))

arr = random.sample(range(1000), n)
print(arr)
pos_max = 0
pos_min = 0
min = 0
max = arr[0]

# max
for i in range(0, 5):
    if(max > arr[i]):
        max = arr[i]
        pos_max = i
# min
for i in range(0, 5):
    if(min < arr[i]):
        min = arr[i]
        pos_min = i

distance = 0
for i in range(0, 5):
    if(pos_min < pos_max):
        distance = pos_max - pos_min
    else:
        distance = pos_min - pos_max

print ("Distance: ", distance)



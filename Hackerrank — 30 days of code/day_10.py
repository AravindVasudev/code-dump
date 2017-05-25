#!/bin/python3

n = bin(int(input().strip()))
_, n = n.split('b')
maxCount = 0
count = 0
for x in n:
    if x == '0':
        maxCount = max(maxCount, count)
        count = 0
    else:
        count += 1
maxCount = max(maxCount, count)
print(maxCount)

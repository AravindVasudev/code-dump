#!/bin/python3

n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]

numSwaps = 0
for i in range(n):
    for j in range(i + 1, n):
        if a[i] > a[j]:
            a[i], a[j] = a[j], a[i]
            numSwaps += 1

print('Array is sorted in {} swaps.'.format(numSwaps))
print('First Element:', a[0])
print('Last Element:', a[n - 1])

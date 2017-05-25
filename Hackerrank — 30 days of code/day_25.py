from math import sqrt

N = int(input())

for _ in range(N):
    val = int(input())
    if val == 1:
        print('Not prime')
        continue

    flag = False
    for i in range(2, int(sqrt(val)) + 1):
        if val % i == 0:
            flag = True
            break
    print("Not prime" if flag else "Prime")

# #!/bin/python3
#
# t = int(input().strip())
# for a0 in range(t):
#     n,k = input().strip().split(' ')
#     n,k = [int(n),int(k)]
#
#     maxi = 0
#     for i in range(1, n + 1):
#         for j in range(i + 1, n + 1):
#             if i&j < k:
#                 maxi = max(maxi, i&j)
#     print(maxi)

T = int(input().strip())
for _ in range(T):
    n , k = map(int , input().split())
    print(k-1 if ((k-1) | k) <= n else k-2)

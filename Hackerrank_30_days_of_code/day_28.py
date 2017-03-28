#!/bin/python3
import re

N = int(input().strip())
names = []
for a0 in range(N):
    firstName,emailID = input().strip().split(' ')
    firstName,emailID = [str(firstName),str(emailID)]

    if re.search('@gmail.com$', emailID):
        names.append(firstName)

print(*sorted(names), sep="\n")

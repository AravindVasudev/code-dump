N = int(input())

phonebook = {}
for _ in range(N):
    name, num = input().split(' ')
    phonebook[name] = num

t = input()
while t != None:
    if t in phonebook:
        print('{}={}'.format(t, phonebook[t]))
    else:
        print('Not found')
    t = input()
    

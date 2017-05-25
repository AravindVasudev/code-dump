T = int(input())

for _ in range(T):
    s = input()
    print("".join([x for i, x in enumerate(s) if not i % 2]), end=" ")
    print("".join([x for i, x in enumerate(s) if i % 2]))

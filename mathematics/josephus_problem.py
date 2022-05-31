def josephus(a, b):
    if a == 1:
        return 1
    else:
        return (josephus(a - 1, b) + b - 1) % a + 1


n = int(input())
k = int(input())
print(josephus(n, k))

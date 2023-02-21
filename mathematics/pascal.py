n = int(input())
res = []

for i in range(0, n):
    row = [1] * (i + 1)
    for j in range(i):
        if j != 0 and j != i:
            row[j] = res[i - 1][j - 1] + res[i - 1][j]

    res.append(row)

for elem in res:
    print(*elem)

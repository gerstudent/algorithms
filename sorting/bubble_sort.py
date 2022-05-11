def bubblesort(a):
    n = len(a)
    for i in range(n):
        swapflag = False
        for j in range(n - i - 1):
            if a[j] > a[j + 1]:
                swapflag = True
                a[j], a[j + 1] = a[j + 1], a[j]
        if not swapflag:
            break


a = list(map(int, input().split()))
bubblesort(a)
for k in range(len(a)):
    print(a[k], end=" ")

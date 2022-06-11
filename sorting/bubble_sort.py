def bubblesort(arr):
    n = len(arr)
    for i in range(n):
        swapflag = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                swapflag = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        if not swapflag:
            break


a = list(map(int, input().split()))
bubblesort(a)
for k in range(len(a)):
    print(a[k], end=" ")

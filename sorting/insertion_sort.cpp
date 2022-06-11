#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int temp, i, j;
    for (i = 1; i < n; ++i) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    inputArray(a, n);
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}

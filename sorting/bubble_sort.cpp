#include "iostream"
#include "bits/stdc++.h"
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapflag;
    for (int i = 0; i < n - 1; ++i) {
        swapflag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swapflag = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!swapflag)
            break;
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
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}

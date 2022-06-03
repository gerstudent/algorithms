#include "iostream"
#include "bits/stdc++.h"
using namespace std;

void bubbleSort(int a[], int n) {
    bool swapflag;
    for (int i = 0; i < n - 1; ++i) {
        swapflag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swapflag = true;
                swap(a[j], a[j + 1]);
            }
        }
        if (!swapflag)
            break;
    }
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n; // number of elements
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubbleSort(a, n);
    printArr(a, n);
    return 0;
}

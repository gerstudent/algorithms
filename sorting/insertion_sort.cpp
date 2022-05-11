#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void inputarr(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}
void insertionSort(int arr[], int n){
    int temp, i, j;
    for (i = 1; i < n; ++i) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void printarr(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

int main() {
    int n; cin >> n; // number of element
    int arr[n];
    inputarr(arr, n);
    insertionSort(arr, n);
    printarr(arr, n);
    return 0;
}
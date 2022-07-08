#include <bits/stdc++.h>
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

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  selectionSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}

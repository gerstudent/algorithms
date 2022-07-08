#include <bits/stdc++.h>
using namespace std;

void heapInit(int arr[], int n, int i) {
  int large = i, l = (i << 1) + 1, r = (i << 1) + 2;
  if (l < n && arr[l] > arr[large]) {
    large = l;
  }
  if (r < n && arr[r] > arr[large]) {
    large = r;
  }
  if (large != i) {
    swap(arr[i], arr[large]);
    heapInit(arr, n, large);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapInit(arr, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapInit(arr, i, 0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  heapSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}

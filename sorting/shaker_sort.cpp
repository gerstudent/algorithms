#include <bits/stdc++.h>
using namespace std;

void shakerSort(int arr[], int n) {
  bool swp = true;
  int begin = 0, end = n - 1;
  while (swp) {
    swp = false;
    for (int i = 0; i < end; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swp = true;
      }
    }
    if (!swp) {
      break;
    }
    swp = false;
    --end;
    for (int i = end - 1; i >= begin; i--) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swp = true;
      }
    }
    ++begin;
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
  shakerSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}
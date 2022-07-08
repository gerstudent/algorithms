#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r) {
  int high = arr[r], small = l;
  for (int i = l; i < r; i++) {
    if (arr[i] <= high) {
      swap(arr[i], arr[small]);
      ++small;
    }
  }
  swap(arr[small], arr[r]);
  return small;
}

void quickSort(int arr[], int l, int r) {
  if (l < r) {
    int part = partition(arr, l, r);
    quickSort(arr, l, part - 1);
    quickSort(arr, part + 1, r);
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
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}
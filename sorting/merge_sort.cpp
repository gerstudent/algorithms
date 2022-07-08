#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
  int left = mid - l + 1, right = r - mid;
  int arr_l[left], arr_r[right];

  for (int i = 0; i < left; i++) {
    arr_l[i] = arr[i + l];
  }

  for (int j = 0; j < right; j++) {
    arr_r[j] = arr[j + mid + 1];
  }

  int i = 0, j = 0, idx = l;

  while (i < left && j < right) {
    if (arr_l[i] <= arr_r[j]) {
      arr[idx] = arr_l[i];
      i++;
    } else {
      arr[idx] = arr_r[j];
      j++;
    }
    idx++;
  }

  while (i < left) {
    arr[idx] = arr_l[i];
    i++;
    idx++;
  }

  while (j < right) {
    arr[idx] = arr_r[j];
    j++;
    idx++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
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
  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}

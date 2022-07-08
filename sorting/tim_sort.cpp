#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    int tmp = arr[i], j = i - 1;
    while (j >= 0 && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = tmp;
  }
}

void merge(int arr[], int l, int mid, int r) {
  int left = mid - l, right = r - mid + 1;
  int arr_l[left], arr_r[right];

  for (int i = 0; i < left; i++) {
    arr_l[i] = arr[left + i];
  }
  for (int j = 0; j < right; j++) {
    arr_r[j] = arr[mid + j + 1];
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

void timSort(int arr[], int size) {
  const int run = 32;
  for (int i = 0; i < size; i += run) {
    insertionSort(arr, i, min(i + run - 1, size - 1));
  }

  for (int num = run; num < size; num <<= 1) {
    for (int l = 0; l < size; l += (num << 1)) {
      int mid = l + num - 1;
      int r = min(l + (num << 1) - 1, size - 1);
      if (mid < r) {
        merge(arr, l, mid, r);
      }
    }
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
  timSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}

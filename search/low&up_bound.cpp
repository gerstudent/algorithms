#include <bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int n, int x) {
  int mid, l = 0, r = n;

  while (l < r) {
    mid = l + (r - l) / 2;
    if (x <= arr[mid]) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  if (l < n && arr[l] < x) {
    l++;
  }
  return l;
}

int upperBound(int arr[], int n, int x) {
  int mid, l = 0, r = n;

  while (l < r) {
    mid = l + (r - l) / 2;
    if (x >= arr[mid]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  if (l < n && arr[l] <= x) {
    l++;
  }
  return l;
}

void printBound(int arr[], int n, int x) {
  int idx = 0;

  if (lowerBound(arr, n, x) == n) {
    cout << "NO SOLUTION\n";
  } else {
    idx = lowerBound(arr, n, x);
    cout << "LB: " << arr[idx] << ' ' << "index: " << idx << '\n';
  }

  if (upperBound(arr, n, x) == n) {
    cout << "NO SOLUTION\n";
  } else {
    idx = upperBound(arr, n, x);
    cout << "UB: " << arr[idx] << ' ' << "index: " << idx << '\n';
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  printBound(arr, n, x);
  return 0;
}

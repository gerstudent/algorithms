/*
    Time Complexity: O(log n)
    Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;

    if (arr[m] == x) {
      return m;
    }
    if (arr[m] < x) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

int main() {
  int n, x;
  cin >> n >> x;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int res = binarySearch(arr, 0, n - 1, x);
  cout << res << '\n';
  return 0;
}

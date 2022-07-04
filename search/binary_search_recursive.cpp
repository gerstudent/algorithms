/*
  Time Complexity: O(log n)
  Auxiliary Space: O(log n)
*/

#include <bits/stdc++.h>
using namespace std;

int binSearchRec(const int arr[], int l, int r, int x) {
  if (r >= l) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) {
      return m;
    }
    if (arr[m] > x) {
      return binSearchRec(arr, l, m - 1, x);
    } else {
      return binSearchRec(arr, m + 1, r, x);
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
  int ans = binSearchRec(arr, 0, n - 1, x);
  cout << ans << '\n';
  return 0;
}

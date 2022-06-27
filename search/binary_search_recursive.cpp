/*
    Time Complexity: O(log n)
    Auxiliary Space: O(log n)
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchRec(const int arr[], int l, int r, int x) {
  if (r >= l) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) {
      return m;
    }
    if (arr[m] > x) {
      return binarySearchRec(arr, l, m - 1, x);
    }
    return binarySearchRec(arr, m + 1, r, x);
  }
  return -1;
}

void inputArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  inputArray(a, n);
  int x;
  cin >> x;
  int ans = binarySearchRec(a, 0, n, x);
  if (ans == -1)
    cout << "Element does not exist in the array";
  else
    cout << "x index: " << ans;
  return 0;
}
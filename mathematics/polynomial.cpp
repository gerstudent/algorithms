#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-9;

ld f(ld num, int arr[], int n) {
  ld cnt = 0.0;
  for (int i = n; i >= 0; i--) {
    cnt += arr[i] * pow(num, i);
  }
  return cnt;
}

void binSearch(int arr[], int n) {
  ld l = -100.0, r = 100.0;
  while (r - l > EPS) {
    ld mid = (l + r) / 2;
    if (f(mid, arr, n) < 0.0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << setprecision(16) << (l + r) / 2.0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = n; i >= 0; i--) {
    cin >> arr[i];
  }
  binSearch(arr, n);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

double areaPolygon(double x[], double y[], int n) {
  double ans = 0.0;
  int idx = n - 1;
  for (int i = 0; i < n; i++) {
    ans += (x[idx] + x[i]) * (y[idx] - y[i]);
    idx = i;
  }
  return abs(ans / 2.0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);

  int n;
  cin >> n;
  double x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << fixed << areaPolygon(x, y, n);
  return 0;
}
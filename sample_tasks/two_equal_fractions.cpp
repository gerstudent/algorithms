// task: https://codeforces.com/problemset/problem/1720/A

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x = a * d, y = b * c;
  if (x == y) {
    cout << "0\n";
  } else if (x % y == 0 && y != 0 || y % x == 0 && x != 0) {
    cout << "1\n";
  } else {
    cout << "2\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
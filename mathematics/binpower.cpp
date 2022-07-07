#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll binpow(ll val, ll power) {
  ll res = 1;
  while (power > 0) {
    if (power & 1) {
      res *= val;
    }
    val *= val;
    power >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll val, power;
  cin >> val >> power;
  cout << binpow(val, power) << '\n';
  return 0;
}
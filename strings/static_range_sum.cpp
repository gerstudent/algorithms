#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> staticRangeSum(const vector<ll>& vec) {
  vector<ll> ans(vec.size() + 1);
  for (size_t i = 0; i < vec.size(); ++i) {
    ans[i + 1] = ans[i] + vec[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  vector<ll> res = staticRangeSum(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << res[r] - res[l] << '\n';
  }
  return 0;
}

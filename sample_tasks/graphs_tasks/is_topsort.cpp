// task: https://stepik.org/lesson/307331/step/14?unit=289419

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using ull = unsigned long long;
using ld = long double;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vpi g;
  vi res(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    g.pb({u, v});
  }
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    res[num] = i;
  }
  for (auto it : g) {
    if (res[it.fi] >= res[it.se]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
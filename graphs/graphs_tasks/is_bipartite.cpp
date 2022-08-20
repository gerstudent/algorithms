// task: https://informatics.msk.ru/mod/statements/view.php?chapterid=165#1

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

vvi g;
vi c;

int invert(int num) { return (2 - (num + 1) % 2); }

void dfs(int v, int color) {
  c[v] = color;
  for (auto u : g[v]) {
    if (!c[u]) {
      dfs(u, invert(color));
    } else if (c[u] == color) {
      cout << "NO\n";
      exit(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  g.resize(n);
  c.resize(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 0; i < n; i++) {
    if (!c[i]) {
      dfs(i, 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (auto u : g[i]) {
      if (c[u] == c[i]) {
        cout << "NO\n";
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    if (c[i] == 1) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}
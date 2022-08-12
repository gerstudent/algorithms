// task: https://stepik.org/lesson/307331/step/2?unit=289419

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vvi g;
vi used, ans;

void dfs(int v) {
  used[v] = 1;
  ans.pb(v + 1);
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
      ans.pb(v + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, v;
  cin >> n >> m;
  g.resize(n + 1);
  used.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  cin >> v;
  dfs(v - 1);
  cout << sz(ans) << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
}

// task: https://stepik.org/lesson/307331/step/3?unit=289419

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vvi g;
vi used, comp;
int n, m, cnt;

void dfs(int v) {
  used[v] = 1;
  comp[v] = cnt;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}

void findComp() {
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      cnt++;
      dfs(i);
    }
  }
}

int main() {
  cin >> n >> m;
  g.resize(n);
  comp.resize(n);
  used.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  cnt = 0;
  findComp();
  cout << cnt << '\n';
  for (auto it : comp) {
    cout << it << ' ';
  }
  return 0;
}
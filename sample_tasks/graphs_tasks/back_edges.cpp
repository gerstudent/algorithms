// task: https://stepik.org/lesson/307331/step/5?unit=289419
// simple solution: cout << m - n

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vi p;
vvi g;

int dfs(int v) {
  int res = 0;
  for (auto u : g[v]) {
    if (!p[u]) {
      p[u] = v;
      res += dfs(u);
    } else {
      if (p[v] != u) {
        res++;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  g.resize(n + 1, vi(0));
  p.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  p[1] = 1;
  cout << (dfs(1) >> 1) << '\n';
  return 0;
}
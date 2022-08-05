// task: https://stepik.org/lesson/307331/step/10?unit=289419

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vvi g;
vi used, p;
bool cycle = false;
int start, finish;

void dfs(int v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) {
      p[to] = v;
      dfs(to);
    } else if (used[to] == 1) {
      cycle = true;
      start = v;
      finish = to;
    }
  }
  used[v] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vi res;
  g.resize(n + 1, vi(0));
  used.resize(n + 1);
  p.resize(n + 1);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }

  if (cycle) {
    cout << "YES\n";
    while (start != finish) {
      res.pb(start);
      start = p[start];
    }
    res.pb(finish);
    reverse(all(res));
    cout << res.size() << '\n';
    for (auto i : res) {
      cout << i + 1 << ' ';
    }
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
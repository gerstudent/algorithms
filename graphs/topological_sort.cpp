// task: https://stepik.org/lesson/307331/step/13?unit=289419

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
bool cycle = false;
int n, m;

void dfs(int v) {
  used[v] = 1;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
    } else if (used[u] == 1) {
      cycle = true;
      return;
    }
  }
  used[v] = 2;
  ans.pb(v);
}

void topologicalSort() {
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  if (!cycle) {
    reverse(all(ans));
    cout << "YES\n";
    for (auto i : ans) {
      cout << i + 1 << ' ';
    }
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  g.resize(n);
  used.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }
  topologicalSort();
  return 0;
}
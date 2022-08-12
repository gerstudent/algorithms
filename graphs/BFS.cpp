// task: https://stepik.org/lesson/307332/step/3?unit=289420

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

int n, m, s;
vi ans, used;
vvi g;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  ans.pb(s);
  used[s] = 1;
  while (!q.empty()) {
    int v = q.front();
    // Print vertices without array (ans):
    // cout << v << ' ';
    q.pop();
    for (int u : g[v]) {
      if (used[u]) {
        continue;
      }
      used[u] = 1;
      q.push(u);
      ans.pb(u);
    }
  }
  for (auto it : ans) {
    cout << it << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  g.resize(n + 1);
  used.resize(n + 1);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  cin >> s;
  bfs(s);
  return 0;
}
// task C: https://codeforces.com/gym/100083

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

const int MAXN = 100500;

vi g[MAXN], idx[MAXN], bridge;
bool used[MAXN];
int timer, tin[MAXN], low[MAXN];

void dfs(int v, int p = -1) {
  used[v] = true;
  timer++;
  tin[v] = timer;
  low[v] = tin[v];
  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];
    if (!used[to]) {
      dfs(to, v);
      if (low[to] == tin[to]) {
        bridge.pb(idx[v][i]);
      }
      low[v] = min(low[v], low[to]);
    } else if (to != p) {
      low[v] = min(low[v], low[to]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  assert(freopen("bridges.in", "r", stdin));
  assert(freopen("bridges.out", "w", stdout));

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int from, to;
    cin >> from >> to;
    g[from].pb(to);
    g[to].pb(from);

    idx[from].pb(i);
    idx[to].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  sort(all(bridge));
  cout << sz(bridge) << '\n';
  for (auto it : bridge) {
    cout << it << ' ';
  }
  return 0;
}

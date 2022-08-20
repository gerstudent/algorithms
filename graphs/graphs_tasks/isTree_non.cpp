// task: https://informatics.msk.ru/mod/statements/view.php?chapterid=111541#1
// Non-oriented graph

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vvi g;
vi used;
int n, comp;

void dfs(int v) {
  used[v] = 1;
  for (int j = 0; j < n; j++) {
    if (g[v][j] == 1 && !used[j]) {
      dfs(j);
    }
  }
}

void findComp() {
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
      comp++;
    }
  }
}

int main() {
  cin >> n;
  int sum = 0;
  used.resize(n, 0);
  g.resize(n, vi(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
      if (g[i][j] == 1) sum++;
    }
  }
  findComp();
  if ((sum >> 1) == n - 1 && comp == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
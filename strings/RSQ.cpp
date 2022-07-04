#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 100500;

ll x, i, l, r;
ll tree[MAXN * 4];

ll summ(int v, int l, int r, int lx, int rx) {
  if (lx > rx) {
    return 0;
  }
  if (lx == l && rx == r) {
    return tree[v];
  }
  int mid = (l + r) / 2;
  return summ(v << 1, l, mid, lx, min(rx, mid)) +
         summ((v << 1) + 1, mid + 1, r, max(lx, mid + 1), rx);
}

void update(int v, int l, int r, int pos, int x) {
  if (l == r) {
    tree[v] = x;
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(v << 1, l, mid, pos, x);
    } else {
      update((v << 1) + 1, mid + 1, r, pos, x);
    }
    tree[v] = tree[v << 1] + tree[(v << 1) + 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  while (k--) {
    char c;
    cin >> c;
    if (c == 'A') {
      cin >> i >> x;
      update(1, 1, n, i, x);
    } else {
      cin >> l >> r;
      cout << summ(1, 1, n, l, r) << '\n';
    }
  }
  return 0;
}

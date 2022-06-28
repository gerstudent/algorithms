#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct segmentTree {
  vector<ll> tree;
  int sz;

  void init(int n) {
    sz = 1;
    while (sz < n) {
      sz <<= 1;
    }
    tree.assign((sz << 1) - 1, 0);
  }

  void build(vector<int>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        tree[x] = a[lx];
      }
    } else {
      int mid = (lx + rx) / 2;
      build(a, (x << 1) + 1, lx, mid);
      build(a, (x << 1) + 2, mid, rx);
      tree[x] = tree[(x << 1) + 1] + tree[(x << 1) + 2];
    }
  }

  void build(vector<int>& a) {
    init(a.size());
    build(a, 0, 0, sz);
  }

  void set(int pos, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (pos < mid) {
      set(pos, v, (x << 1) + 1, lx, mid);
    } else {
      set(pos, v, (x << 1) + 2, mid, rx);
    }
    tree[x] = tree[(x << 1) + 1] + tree[(x << 1) + 2];
  }

  void set(int pos, int v) { set(pos, v, 0, 0, sz); }

  ll sum(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) {
      return 0;
    }
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int mid = (lx + rx) / 2;
    ll suml = sum(l, r, (x << 1) + 1, lx, mid);
    ll sumr = sum(l, r, (x << 1) + 2, mid, rx);
    return suml + sumr;
  }

  ll sum(int l, int r) { return sum(l, r, 0, 0, sz); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  segmentTree st;
  st.build(a);

  for (int t = 0; t < m; t++) {
    int c;
    cin >> c;
    if (c == 1) {
      int i, v;
      cin >> i >> v;
      st.set(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.sum(l, r) << '\n';
    }
  }
  return 0;
}
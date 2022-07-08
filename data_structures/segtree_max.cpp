#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

template <typename T>
inline T* const& maximum(T* const& a, T* const& b) {
  return *a < *b ? b : a;
}

struct segmentTree {
  size_t tree_sz;
  int* val;
  int** tree;

  segmentTree(size_t sz)
      : tree_sz(sz), val(new int[sz]), tree(new int*[4 * sz]) {}

  int* build_tree(int v, int lx, int rx) {
    if (lx == rx) {
      return (tree[v] = lx + val);
    }
    int mid = (lx + rx) / 2;
    int* l_max = build_tree((v << 1), lx, mid);
    int* r_max = build_tree((v << 1) + 1, mid + 1, rx);
    return (tree[v] = maximum(l_max, r_max));
  }

  segmentTree(int* start, int* end)
      : tree_sz(end - start), val(start), tree(new int*[4 * (end - start)]) {
    build_tree(1, 0, tree_sz - 1);
  }

  const int* maxVal(int l, int r, int v, int lx, int rx) {
    if (l <= lx && rx <= r) {
      return tree[v];
    }
    static const int minimal{INT_MIN};
    if (rx < l || r < lx) {
      return &minimal;
    }
    int mid = (lx + rx) / 2;
    const int* l_max = maxVal(l, r, (v << 1), lx, mid);
    const int* r_max = maxVal(l, r, (v << 1) + 1, mid + 1, rx);
    return maximum(l_max, r_max);
  }

  const int* maxVal(int l, int r) { return maxVal(l, r, 1, 0, tree_sz - 1); }

  ~segmentTree() {
    delete[] tree;
    delete[] val;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n;
  int k;
  cin >> n;
  int* a = new int[n];
  for (int* i = a; i != a + n; i++) {
    cin >> *i;
  }

  segmentTree tree(a, a + n);
  pii rng;

  cin >> k;
  while (k--) {
    cin >> rng.first >> rng.second;
    const int* ans = tree.maxVal(rng.first - 1, rng.second - 1);
    cout << *ans << ' ' << ans - a + 1 << '\n';
  }
  return 0;
}
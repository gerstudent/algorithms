#include <bits/stdc++.h>
using namespace std;

bool checkBit(int arr[], int idx) {
	return arr[idx >> 5] & (1 << (idx & 31)); 
}

void setBit(int arr[], int idx) { 
	arr[idx >> 5] |= (1 << (idx & 31));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, l, r, size;
  cin >> n >> m >> l >> r;
  size = ceil((long double)(abs(r - l) + 1) / 32);

  int arr[size];
  for (int i = l; i <= r; i++) {
    if (i % n == 0 || i % m == 0) {
      setBit(arr, i - l);
    }
  }
  for (int i = l; i <= r; i++) {
    if (checkBit(arr, i - l)) {
      cout << i << ' ';
    }
  }
  return 0;
}

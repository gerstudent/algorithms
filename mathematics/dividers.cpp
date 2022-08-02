#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

vector<ull> findDividers(ull x) {
  vector<ull> divs;
  for (ull i = 1; i <= sqrt(x); i++) {
    if (x % i == 0) {
      divs.push_back(i);
      if (i * i != x) {
        divs.push_back(x / i);
      }
    }
  }
  return divs;
}

int main() {
  int n;
  cin >> n;

  vector<ull> divs = findDividers(n);
  sort(divs.begin(), divs.end());

  cout << divs.size() << '\n';
  for (ull i : divs) {
    cout << i << ' ';
  }
  return 0;
}

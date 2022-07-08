#include <bits/stdc++.h>
using namespace std;

vector<unsigned> findDividers(unsigned x) {
  vector<unsigned> dividers;
  for (unsigned i = 1; i <= sqrt(x); i++) {
    if (x % i == 0) {
      dividers.push_back(i);
      if (i * i != x) {
        dividers.push_back(x / i);
      }
    }
  }
  return dividers;
}

int main() {
  int n;
  cin >> n;
  vector<unsigned> divs = findDividers(n);
  sort(divs.begin(), divs.end());
  cout << divs.size() << endl;
  for (unsigned div : divs) {
    cout << div << ' ';
  }
  return 0;
}

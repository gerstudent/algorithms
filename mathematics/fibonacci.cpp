#include <bits/stdc++.h>
using namespace std;

unsigned long long fib(unsigned long long n) {
  unsigned long long a = 0, b = 1, i;
  for (i = 0; i < n; i++) {
    a = a + b;
    b = a - b;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned long long n;
  cin >> n;
  cout << fib(n) << '\n';
  return 0;
}
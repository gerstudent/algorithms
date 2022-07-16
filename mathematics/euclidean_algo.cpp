#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b; 
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << "gcd: " << gcd(a, b) << ' ' << "lcm: " << lcm(a, b);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
  string s = to_string(x);
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int x;
  cin >> x;
  cout << isPalindrome(x) << "\n";
  return 0;
}
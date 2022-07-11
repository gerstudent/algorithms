#include <bits/stdc++.h>
using namespace std;

int toInt(char c) {
  if (c >= '0' && c <= '9') {
    return (int)c - '0';
  } else {
    return (int)c - 'A' + 10;
  }
}

int toDecimal(string s, int base) {
  int len = s.length(), power = 1, num = 0;
  for (int i = len - 1; i >= 0; i--) {
    num += toInt(s[i]) * power;
    power *= base;
  }
  return num;
}

char toChar(int num) {
  if (num >= 0 && num <= 9) {
    return (char)(num + '0');
  } else {
    return (char)(num - 10 + 'A');
  }
}

string toBase(int num, int base) {
  string ans = "";
  while (num > 0) {
    ans += toChar(num % base);
    num /= base;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void convert(string s, int from, int to) {
  int num = toDecimal(s, from);
  string ans = toBase(num, to);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string num;
  int from, to;
  cin >> num >> from >> to;
  convert(num, from, to);
  return 0;
}

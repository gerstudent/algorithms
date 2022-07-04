#include <bits/stdc++.h>
using namespace std;

vector<int> prefFun(string str) {
  int len = str.length();
  vector<int> pf(len, 0);
  for (int i = 1; i < len; ++i) {
    int step = pf[i - 1];
    while (step > 0 && str[i] != str[step]) {
      step = pf[step - 1];
    }
    if (str[i] == str[step]) {
      pf[i] = step + 1;
    }
  }
  return pf;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;
  vector<int> ans = prefFun(str);
  for (size_t i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
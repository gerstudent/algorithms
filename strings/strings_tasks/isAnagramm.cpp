#include <bits/stdc++.h>
using namespace std;

bool isAnagramm(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }

  unordered_map<char, int> mp;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]]++;
  }

  for (int i = 0; i < t.length(); i++) {
    if (mp.find(t[i]) != mp.end()) {
      mp[t[i]]--;
    } else {
      return false;
    }
  }

  for (auto i : mp) {
    if (i.second != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  if (isAnagramm(s, t)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
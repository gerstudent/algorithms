#include <bits/stdc++.h>
using namespace std;

void preprocessing(char* p, int size, int lps[]) {
  int prev = 0, i = 1;
  lps[0] = 0;
  while (i < size) {
    if (p[i] == p[prev]) {
      prev++;
      lps[i] = prev;
      i++;
    } else {
      if (prev != 0) {
        prev = lps[prev - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

void KMP(char* p, char* t) {
  int n = strlen(t), m = strlen(p), i = 0, j = 0;
  int lps[m];
  preprocessing(p, m, lps);
  while ((n - i) >= (m - j)) {
    if (p[j] == t[i]) {
      i++;
      j++;
    }
    if (j == m) {
      cout << "pattern index: " << i - j << '\n';
      j = lps[j - 1];
    } else if (n > i && p[j] != t[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
}

int main() {
  char t[] = "find pattern", p[] = "pattern";
  KMP(p, t);
  return 0;
}
// task: https://stepik.org/lesson/13027/step/16?unit=4379

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef vector<int> vi;

bool check(vi& field, int queens, int pos) {
  for (int j = 0; j < queens; j++) {
    bool case1 = field[j] == pos;
    bool case2 = j - field[j] == queens - pos;
    bool case3 = j + field[j] == queens + pos;
    if (case1 || case2 || case3) {
      return false;
    }
  }
  return true;
}

void backtracking(vi& field, int queens, int& cnt) {
  if (queens == sz(field)) {
    cnt++;
  } else {
    for (int i = 0; i < sz(field); i++) {
      if (check(field, queens, i)) {
        field[queens] = i;
        backtracking(field, queens + 1, cnt);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, cnt = 0;
  cin >> n;
  vi field(n);
  backtracking(field, 0, cnt);
  cout << cnt << '\n';
  return 0;
}

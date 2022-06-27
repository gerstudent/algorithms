#include <bits/stdc++.h>

#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, W;
  cin >> W >> n;
  vector<int> wt(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> wt[i];
  }

  vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= W; ++j) {
      if (wt[i] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - wt[i]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  for (int i = W; i >= 0; --i) {
    if (dp[n][i] == 1) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}
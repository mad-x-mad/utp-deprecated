#include<bits/stdc++.h>
using namespace std;

const int len = 'z' - 'a' + 1;
int dp[55][55];

int f(string &s, int i, int j) {
  if (i == s.size() or j == len) {
    return len - j;
  }

  if (dp[i][j] == -1) {
    char ch = j + 'a';
    if (s[i] == ch) {
      dp[i][j] = f(s, i + 1, j + 1);
    } else {
      int a = 1 + f(s, i, j + 1);
      int b = f(s, i + 1, j);
      dp[i][j] = min(a, b);
    }
  }

  return dp[i][j];
}

int main() {
  string s;
  while (cin >> s) {
    memset(dp, -1, sizeof dp);
    int ans = f(s, 0, 0);
    cout << ans << endl;
  }
return 0;
}

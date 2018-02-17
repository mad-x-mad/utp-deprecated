#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int maxn = 500;
int mark[maxn][maxn];
double dp[maxn][maxn];

double f(int n, int k) {
  if (!k) return 0;
  if (n == 1) return 0.5;

  if (mark[n][k] == 0) {
    double a = 1 + f(n - 1, k - 1);
    double b = f(n, k - 1);

    mark[n][k] = 1;
    dp[n][k] = (a + b) / 2;
  }

  return dp[n][k];
}

int main() { IO;
  int n, k;
  cin >> n >> k;

  double ans = f(n, k);
  cout << setprecision(9) << fixed << ans << endl;

  return 0;
}

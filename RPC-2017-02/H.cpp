#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

#define D(x) cout << #x << " = " << x << endl;

const int maxn = 1000000;
long long dp[maxn];
long long f(vector<pair<long long, long long>> &v, vector<int> &next, int i) {
  int n = v.size();
  if (i == n) return 0;

  if (dp[i] == -1) {
    long long a = v[i].second - v[i].first + 1 + f(v, next, next[i]);
    long long b = f(v, next, i + 1);
    dp[i] = max(a, b);
  }

  return dp[i];
}

int main() { IO;
  long long n, k;
  cin >> n >> k;

  vector<pair<long long, long long>> v(k);
  for (int i = 0; i < k; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());

  vector<int> next(k, k);
  for (int i = 0; i < k; ++i) {
    auto it = lower_bound(v.begin(), v.end(), make_pair(v[i].second + 1LL, 0LL));
    if (it == v.end()) continue;
    next[i] = it - v.begin();
  }

  memset(dp, -1, sizeof dp);
  long long ans = f(v, next, 0);
  cout << n - ans << endl;

  return 0;
}

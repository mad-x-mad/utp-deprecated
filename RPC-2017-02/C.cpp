#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << x << endl;

int main() {
  int n, k, r;
  cin >> n >> k >> r;

  vector<int> v(n);
  for (int i = 0; i < k; ++i) {
    int xi;
    cin >> xi;
    v[xi - 1] = 1;
  }

  int ans = 0;
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    cnt += v[i];
    if (i < r - 1) continue;

    int j = i - r;
    if (j >= 0) {
      cnt -= v[j];
    }

    int t = i;
    while (cnt < 2) {
      while (v[t]) t--;
      v[t] = 1;
      cnt++;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

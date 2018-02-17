#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) // cout << #x << " = " << (x) << endl;

int main() { IO;
  int n;
  cin >> n;

  vector<int> h(n), r(n), t(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i] >> r[i] >> t[i];
  }

  int H = *max_element(h.begin(), h.end());
  D(H);
  vector<int> v(H * 1825);

  for (int i = 0; i < n; ++i) {
    D(i);
    vector<int> dark(h[i]);
    {
      int hour = t[i] % h[i];
      while (true) {
        D(hour);
        dark[hour] = 1;
        if (hour == r[i]) break;
        hour = (hour + 1) % h[i];
      }
    }

    for (int j = 0; j < v.size(); ++j) {
      int hour = j % h[i];
      if (dark[hour]) v[j]++;
    }
  }

  int ans = -1;
  for (int i = 0; i < v.size(); ++i) {
    D(i); D(v[i]);
    if (v[i] == n) {
      ans = i;
      break;
    }
  }

  if (ans == -1) cout << "impossible" << endl;
  else cout << ans << endl;

  return 0;
}

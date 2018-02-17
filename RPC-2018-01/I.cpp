#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO;
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  int t;
  cin >> t;

  int ans;
  int rem = t;

  for (int i = 0; i < n; ++i) {
    int h = v[i];

    int r = t - h * (t / h);
    if (r < rem) {
      rem = r;
      ans = i;
    }
  }

  cout << v[ans] << endl;

  return 0;
}

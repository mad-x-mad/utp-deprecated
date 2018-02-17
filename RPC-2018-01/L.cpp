#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int lis(vector<int> &v) {
  vector<int> l;
  for (int i = 0; i < v.size(); i++) {
    auto it = lower_bound(l.begin(), l.end(), v[i]);
    if (it == l.end()) {
      l.push_back(v[i]);
    } else {
      *it = v[i];
    }
  }

  return l.size();
}

int main() { IO;
  int tx, ty;
  cin >> tx >> ty;

  int n;
  cin >> n;

  vector<tuple<long long, long long, long long, long long>> v;
  for (int i = 0; i < n; ++i) {
    long long x, y, h;
    cin >> x >> y >> h;

    x = (x - tx);
    y = (y - ty);
    long long d = x * x + y * y;

    v.push_back(make_tuple(d, h, x, y));
  }

  sort(v.begin(), v.end());

  map<pair<int,int>, vector<int>> room;
  for (int i = 0; i < n; ++i) {
    int h = get<1>(v[i]);
    int x = get<2>(v[i]);
    int y = get<3>(v[i]);

    int g = __gcd(x, y);
    x /= abs(g);
    y /= abs(g);
    // D(g); D(x); D(y);

    room[{x, y}].push_back(h);
  }

  // D(room.size());
  int ans = 0;
  for (auto &x : room) {
    int cnt = lis(x.second);
    // D(cnt);
    ans += cnt;
  }

  cout << ans << endl;

  return 0;
}

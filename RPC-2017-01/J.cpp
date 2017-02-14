#include<bits/stdc++.h>
using namespace std;

#define D(x) // cout << #x << " = " << x << endl;

const int maxn = 1000 * 1000;

struct wave {
  int i, at, points, to;

  wave () {}

  wave (int _i, int _at, int _points, int _to) :
    i(_i), at(_at), points(_points), to(_to)
  {};
};

long long dp[maxn];
long long f(int i, map<int,wave> &m, vector<wave> &waves) {
  int n = waves.size();
  if (i == n) return 0;

  if (dp[i] == -1) {
    long long ans = f(i + 1, m , waves);

    wave &w = waves[i];
    int points = w.points;
    long long b = points;

    auto it = m.lower_bound(w.to);
    if (it != m.end()) {
      int next = (*it).second.i;
      D(i); D(next);
      b += f(next, m, waves);
    }
    ans = max(ans, b);

    dp[i] = ans;
  }

  return dp[i];
}

bool cmp(const wave &a, const wave &b) {
  return a.at < b.at;
}

int main() {
  int n;
  cin >> n;

  vector<wave> waves;
  for (int i = 0; i < n; ++i) {
    int at, points, duration;
    cin >> at >> points >> duration;

    wave w(i, at, points, at + duration);
    waves.push_back(w);
  }

  sort(waves.begin(), waves.end(), cmp);

  int id = 0;
  map<int, wave> m;
  for (auto &w : waves) {
    w.i = id;
    id++;
    m[w.at] = w;
  }

  memset(dp, -1, sizeof dp);
  long long ans = f(0, m, waves);
  cout << ans << endl;

  return 0;
}

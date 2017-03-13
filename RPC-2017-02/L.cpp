#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

#define D(x) cout << #x << " = " << x << endl;

int main() { IO;
  int n, m;
  cin >> n >> m;

  vector<int> b(n);
  for (auto &x : b) cin >> x;

  vector<int> p(m);
  for (auto &x : p) cin >> x;

  unordered_map<int, long long> P;
  for (int mask = 0; mask < (1 << m); ++mask) {
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
      if ((mask >> i) & 1) {
	sum += p[i];
      }
    }
    P[mask] = sum;
  }

  unordered_set<long long> dist_p;
  for (int mask1 = 0; mask1 < (1 << m); ++mask1) {
    for (int mask2 = 0; mask2 < (1 << m); ++mask2) {
      if (mask1 & mask2) continue;
      if (P[mask1] != P[mask2]) continue;
      dist_p.insert(P[mask1]);
    }
  }

  unordered_set<long long> dist_b;
  for (auto &x : b) dist_b.insert(x);

  set<long long> dist;
  for (auto &y : dist_b) {
    dist.insert(y);
    for (auto &x : dist_p) {
      dist.insert(x + y + x);
    }
  }

  for (auto & x : dist) cout << x << endl;

  return 0;
}

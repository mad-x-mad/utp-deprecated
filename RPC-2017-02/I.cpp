#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

#define D(x) cout << #x << " = " << x << endl;

long long f(vector<pair<long long, long long>> &v, long long k) {
  long long cnt = 0;
  long long free = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (free >= v[i].second) {
      free -= v[i].second;
    } else {
      v[i].second -= free;
      free = 0;
      long long x = v[i].second / k;
      cnt += x * v[i].first;
      v[i].second -= x * k;

      if (v[i].second) {
	cnt += v[i].first;
	free = k - v[i].second;
      }
    }
  }

  return cnt;
}

int main() {
  long long n, k;
  cin >> n >> k;

  vector<pair<long long, long long>> a, b;
  for (int i = 0; i < n; ++i) {
    long long x, cnt;
    cin >> x >> cnt;
    if (x >= 0) {
      a.push_back({abs(x), cnt});
    } else {
      b.push_back({abs(x), cnt});
    }
  }

  sort(a.begin(), a.end(), greater<pair<long long, long long>>());
  sort(b.begin(), b.end(), greater<pair<long long, long long>>());

  long long ans = f(a, k) + f(b, k);
  cout << 2LL * ans << endl;

  return 0;
}

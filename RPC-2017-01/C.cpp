#include<bits/stdc++.h>
using namespace std;

typedef pair<string, string> pss;

int main() {
  int n;
  cin >> n;

  vector<pss> v(n);
  string a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    v[i] = {b, a};
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) cout << v[i].second << " " << v[i].first << endl;

  return 0;
}

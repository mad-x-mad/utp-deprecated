#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO;
  int n;
  cin >> n;

  double ans = 0;
  for (int i = 0; i < n; ++i) {
    int code;
    cin >> code;

    if (code == 0) ans += 2;
    else ans += 1. / code;
  }

  cout << setprecision(6) << fixed << ans << endl;

  return 0;
}

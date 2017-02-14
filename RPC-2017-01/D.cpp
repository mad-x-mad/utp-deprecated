#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while(cin >> s) {
    map<char, int> cnt;
    for (int i = 0; i < s.size(); ++i) cnt[s[i]] ++;

    vector<int> v;
    for (auto i: cnt) {
      v.push_back(i.second);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (v.size() - i <= 2) break;
      ans += v[i];
    }

    cout << ans << endl;
  }

  return 0;
}

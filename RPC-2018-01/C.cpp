#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO;
  int n;
  cin >> n;

  vector<int> balls;
  int red = 0;
  for (int i = 0; i < n; ++i) {
    string color;
    cin >> color;

    int value;

    if (color == "red")  value = 1;
    if (color == "yellow") value = 2;
    if (color == "green") value = 3;
    if (color == "brown") value = 4;
    if (color == "blue" ) value = 5;
    if (color == "pink" ) value = 6;
    if (color == "black") value = 7;

    if (value == 1) red++;
    else balls.push_back(value);
  }

  int ans = 1;
  if (balls.size()) {
    int mx = *max_element(balls.begin(), balls.end());
    int sum = accumulate(balls.begin(), balls.end(), 0);

    ans = red + (red + 1) * mx + sum - mx;
  }

  cout << ans << endl;

  return 0;
}

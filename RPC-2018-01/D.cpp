#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO;
  string original;
  cin >> original;

  string sorted = original;
  sort(sorted.begin(), sorted.end());

  for (int i = 0; i < original.size(); ++i) {
    if (sorted[i] == original[i]) continue;

    int j = i + 1;
    while (sorted[j] != original[i]) j++;

    if (sorted[j] > sorted[i]) {
      cout << j + 1 << " " << i + 1 << endl;
    } else {
      cout << i + 1 << " " << j + 1 << endl;
    }

    swap(sorted[i], sorted[j]);
  }

  return 0;
}

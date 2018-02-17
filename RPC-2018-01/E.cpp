#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct department {
  int id, students, to;
  bool operator<(const struct department &o) const {
    return students < o.students;
  }
};

struct building {
  int id, cap, cost;
  bool operator<(const struct building &o) const {
    if (cost == o.cost) return cap < o.cap;
    return cost < o.cost;
  }
};

int main() { IO;
  int n, m;
  cin >> n >> m;

  vector<department> departments(n);
  vector<building> buildings(m);

  for (int i = 0; i < n; ++i) {
    departments[i].id = i;
    departments[i].to = -1;
    cin >> departments[i].students;
  }

  for (int j = 0; j < m; ++j) {
    buildings[j].id = j;
    cin >> buildings[j].cap;
  }

  for (int j = 0; j < m; ++j) {
    cin >> buildings[j].cost;
  }

  sort(departments.begin(), departments.end());
  sort(buildings.begin(), buildings.end());

  // for (int i = 0; i < n; ++i) {
  //   cout << departments[i].id << " " << departments[i].students << endl;
  // }
  // cout << "--" << endl;
  // for (int j = 0; j < m; ++j) {
  //   cout << buildings[j].id << " " << buildings[j].cap << " " << buildings[j].cost << endl;
  // }
  // cout << "--" << endl;

  for (auto &building : buildings) {
    for (int i = n - 1; i >= 0; --i) {
      auto &department = departments[i];
      if (department.to != -1) continue;

      if (department.students <= building.cap) {
        department.to = building.id;
        break;
      }
    }
  }

  vector<int> ans(n);
  for (auto &department : departments) {
    ans[department.id] = department.to;
  }

  int cnt = count(ans.begin(), ans.end(), -1);
  if (cnt) {
    cout << "impossible" << endl;
    return 0;
  }
  
  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;

  return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int d_row[] = { 1, 0,-1, 0};
const int d_col[] = { 0, 1, 0,-1};

bool is_valid(int x, int n) {
  return 0 <= x and x < n;
}

struct state {
  int row, col, steps;
  state (int _row, int _col, int _steps) : row(_row), col(_col), steps(_steps) {}
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (auto &line : grid) cin >> line;

  int mark[n][m];
  memset(mark, 0, sizeof mark);
  mark[0][0] = 1;

  queue<state> q;
  state st(0, 0, 0);
  q.push(st);

  int ans = -1;
  while (q.size()) {
    state cur = q.front();
    q.pop();
    int d = grid[cur.row][cur.col] - '0';

    if (cur.row == n - 1 and cur.col == m - 1) {
      ans = cur.steps;
      break;
    }

    for (int k = 0; k < 4; ++k) {
      int row = cur.row + d_row[k] * d;
      int col = cur.col + d_col[k] * d;
      if (!is_valid(row, n) or !is_valid(col, m) or mark[row][col]) continue;

      mark[row][col] = 1;
      state next(row, col, cur.steps + 1);
      q.push(next);
    }
  }

  if (ans == -1) cout << "IMPOSSIBLE" << endl;
  else cout << ans << endl;

  return 0;
}

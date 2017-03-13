#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

#define D(x) cout << #x << " = " << x << endl;

const int maxn = 55;
const int inf = 1000000;
const string ops = "URDL";
const int di[] = {-1, 0, 1, 0};
const int dj[] = { 0, 1, 0,-1};

bool is_valid(int x, int n) {
  return 0 <= x and x < n;
}

typedef struct state state;
struct state {
  int cnt, index, i, j;
  state();
  state(int _cnt, int _index, int _i, int _j) : cnt(_cnt), index(_index), i(_i), j(_j) { }
  bool operator <(const state &o) const {
    if (cnt != o.cnt) return cnt > o.cnt;
    if (index != o.index) return index > o.index;
    if (i != o.i) return i > o.i;
    return j > o.j;
  }
  friend ostream& operator <<(ostream& stream, state &s){
    stream << endl;
    stream << "  cnt: " << s.cnt << endl;
    stream << "  index: " << s.index << endl;
    stream << "  i: " << s.i << endl;
    stream << "  j: " << s.j;
    return stream;
  }
};

state apply(state &cur, char op, vector<string> &grid, string &cmd) {
  int n = grid.size();
  int m = grid[0].size();

  int i_new = cur.i + di[ops.find(op)];
  int j_new = cur.j + dj[ops.find(op)];
  if (!is_valid(i_new, n) or !is_valid(j_new, m) or grid[i_new][j_new] == '#') {
    i_new = cur.i;
    j_new = cur.j;
  }

  int cnt_new, index_new;
  if (cur.index < cmd.size() and op == cmd[cur.index]) {
    cnt_new = cur.cnt;
    index_new = cur.index + 1;
  } else {
    cnt_new = cur.cnt + 1;
    index_new = cur.index;
  }

  state next(cnt_new, index_new, i_new, j_new);
  return next;
}

int main() { IO;
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (auto &line : grid) cin >> line;

  string cmd;
  cin >> cmd;

  int i_r, j_r, i_e, j_e;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.' or grid[i][j] == '#') continue;
      if (grid[i][j] == 'R') { i_r = i; j_r = j; }
      if (grid[i][j] == 'E') { i_e = i; j_e = j; }
      grid[i][j] = '.';
    }
  }

  // D(i_r); D(j_r);
  // D(i_e); D(j_e);

  state initial(0, 0, i_r, j_r);  // cnt, index, i, j

  priority_queue<state> pq;
  pq.push(initial);

  int mark[maxn][maxn][maxn];
  memset(mark, inf, sizeof mark);
  mark[i_r][j_r][0] = 0;

  int ans = INT_MAX;
  while (pq.size()) {
    state cur = pq.top(); pq.pop();
    if (cur.cnt > mark[cur.i][cur.j][cur.index]) {
      continue;
    }
    // D(cur);
    if (cur.i == i_e and cur.j == j_e) {
      ans = min(ans, cur.cnt);
    }

    for (char op : ops) {
      state next = apply(cur, op, grid, cmd);
      // D(op); D(next);
      if (mark[next.i][next.j][next.index] > next.cnt) {
        mark[next.i][next.j][next.index] = next.cnt;
        pq.push(next);
      }
    }
  }

  cout << ans << endl;

  return 0;
}

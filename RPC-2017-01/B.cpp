#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int n;
bool visited[33][33][222];
int dx[] = {1, -1, -1,  1};
int dy[] = {1,  1, -1, -1};

bool good (int x, int y, int x2, int y2, vector<vector<char>> &chess) {
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  if (chess[x][y] != 'W') return false;

  if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) return false;
  if (chess[x2][y2] != '_') return false;

  return true;
}

bool check (int x, int y, int w, vector<vector<char>> &chess) {
  if (w == 0) return true;
  visited[x][y][w] = true;

  int ok = 0;
  for (int i = 0; i < 4; ++i) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];
    int x2 = x1 + dx[i];
    int y2 = y1 + dy[i];

    if (good(x1, y1, x2, y2, chess) && !visited[x2][y2][w - 1]) {

      chess[x][y] = '_';
      chess[x1][y1] = '_';
      chess[x2][y2] = 'B';

      ok += check(x2, y2, w - 1, chess);
      if (ok) return ok;

      chess[x][y] = 'B';
      chess[x1][y1] = 'W';
      chess[x2][y2] = '_';
    }
  }

  return ok;
}

int main() { IO
  while (cin >> n) {
    int w = 0;
    vector<vector<char>> board(n, vector<char>(n)), board2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> board[i][j];
        w += (board[i][j] == 'W');
      }
    }

    int times = 0;
    int x, y;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'B') {
          memset(visited, 0, sizeof visited);
          board2 = board;

          bool ok = check(i, j, w, board2);
          if (ok) {
            x = i;
            y = j;
            times ++;
          }
        }
      }
    }

    if (times == 0) cout << "None" << endl;
    else if (times != 1) cout << "Multiple" << endl;
    else cout << char(y + 'a') << n - x << endl;
  }

  return 0;
}

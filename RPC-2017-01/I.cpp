#include<bits/stdc++.h>
using namespace std;

#define D(x) // cout << #x << " = " << x << endl;

int r;

struct point {
  long long x, y;
  point (long long _x, long long _y) : x(_x), y(_y) {}
  point operator +(const point &o){
    point p(x + o.x, y + o.y);
    return p;
  }
  point operator -(const point &o){
    point p(x - o.x, y - o.y);
    return p;
  }
  point operator *(const long long d) {
    point p(x * d, y * d);
    return p;
  }
  bool operator<(const point &b) const {
    point o(1, r);
    point c = point(b.x - x, b.y - y);

    long long d = c.cross(o);
    return d < 0;
  }
  long long cross(const point &o) {
    return x * o.y - y * o.x;
  }
  long long dist(const point &o) {
    return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
  }
  friend ostream& operator <<(ostream& stream, point &p){
    stream << "(" << p.x << "," << p.y << ")";
    return stream;
  }
};

int lis(vector<point> &v) {
  vector<point> inc;

  for (auto &x : v) {
    auto it = upper_bound(inc.begin(), inc.end(), x);
    if (it == inc.end()) {
      inc.push_back(x);
    } else {
      *it = x;
    }
  }

  return inc.size();
}

bool cmp(const point &a, const point &b) {
  point o(-1, r);
  point c = point(b.x - a.x, b.y - a.y);

  long long cross = c.cross(o);
  if (cross) return cross > 0;

  return a < b;
}

int main() {
  int n, w, h;
  cin >> n >> r >> w >> h;

  vector<point> v;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    point p(x, y);
    v.push_back(p);
  }

  sort(v.begin(), v.end(), cmp);

  int ans = lis(v);
  cout << ans << endl;

  return 0;
}

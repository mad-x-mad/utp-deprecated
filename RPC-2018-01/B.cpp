#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const double EPS = 1e-7;

struct point{
  double x, y;
  point() {}
  bool operator <(const point &p) const{
    return x < p.x || (x == p.x && y < p.y);
  }
  double dist(point &o){
    double d = (x - o.x)*(x - o.x);
    d += (y - o.y)*(y - o.y);
    d = sqrt(d);
    return d;
  }
  double cross_product(const point &a, const point &b){
    return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
  }
};

struct line{
  point a, b;
  line(point A, point B) : a(A), b(B) {}
  double dist(point &pnt) {
    double num = (b.y - a.y) * pnt.x - (b.x - a.x) * pnt.y + b.x * a.y - b.y * a.x;
    double dist_ab = a.dist(b);
    
    double d = abs(num) / dist_ab;
    return d;
  }
};

vector<point> convex_hull(vector<point> &P){
  int n = P.size(), k = 0;
  vector<point> H(2 * n);
  sort(P.begin(), P.end());

  for(int i = 0; i < n; ++i){
    while(k >= 2 and H[k-2].cross_product(H[k-1], P[i]) < 0) k--;
    H[k] = P[i];
    k++;
  }

  for(int i = n - 2, t = k + 1; i >= 0; --i){
    while(k >= t and H[k-2].cross_product(H[k-1], P[i]) < 0) k--;
    H[k] = P[i];
    k++;
  }
  H.resize(k);
  
  return H;
}


int main() { IO;
  int n;
  cin >> n;

  vector<point> P(n);
  for (auto &p : P) {
    cin >> p.x >> p.y;
  }

  vector<point> H = convex_hull(P);

  double min_distance = DBL_MAX;
  for (int i = 1; i < H.size(); ++i) {
    line l(H[i - 1], H[i]);
    double max_line_distance = 0;
    for (int k = 0; k < H.size(); ++k) {
      double line_point_distance = l.dist(H[k]);
      max_line_distance = max(max_line_distance, line_point_distance);
    }

    min_distance = min(min_distance, max_line_distance);
  }

  cout << setprecision(7) << fixed << min_distance << endl;

  return 0;
}

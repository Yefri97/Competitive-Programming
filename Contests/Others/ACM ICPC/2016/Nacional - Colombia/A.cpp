/*
 *  ACM ICPC XXX Colombian Programming Contest 2016
 *  Problem A: ACIS, A Contagious vIruS
 *  Status: Accepted \ Geometry
 */

#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }

point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }

double dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  point c = translate(a, scale(ab, u));
  return dist(p, c);
}

double distToLineSegment(point p, point a, point b) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) return dist(p, a);
  if (u > 1.0) return dist(p, b);
  return distToLine(p, a, b);
}

int main() {
  string s;
  while(cin >> s && s != "*") {
    int n = atoi(s.c_str());
    point r; cin >> r.x >> r.y;
    vector<point> arr;
    while (n--) {
      point p; cin >> p.x >> p.y;
      arr.push_back(p); 
    }
    arr.push_back(arr[0]);
    double ans = 1000.0;
    for (int i = 0; i < arr.size() - 1; i++)
      ans = min(ans, distToLineSegment(r, arr[i], arr[i + 1]));
    cout << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-5;

struct point { double x, y; };
struct line { double a, b, c; };

bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

point intersectPoint(line l1, line l2) {
  point p;
  p.x  = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    p.y = -(l1.a * p.x + l1.c);
  else
    p.y = -(l2.a * p.x + l2.c);
  return p;
}

line pointsToLine(point p1, point p2) {
  line l;
  if (fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0;
    l.b = 0.0;
    l.c = -p1.x;
  } else {
    l.a = -(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(l.a * p1.x) - p1.y;
  }
  return l;
}

int main() {
  int t; cin >> t;
  cout << "INTERSECTING LINES OUTPUT" << endl;
  while (t--) {
    point a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y >> b1.x >> b1.y >> b2.x >> b2.y;
    line la = pointsToLine(a1, a2), lb = pointsToLine(b1, b2);
    if (areSame(la, lb))
      cout << "LINE" << endl;
    else if (areParallel(la, lb))
      cout << "NONE" << endl;
    else {
      point ans = intersectPoint(la, lb);
      cout << "POINT " << fixed << setprecision(2) << ans.x << " " << ans.y << endl;
    }
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
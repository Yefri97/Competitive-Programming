#include <bits/stdc++.h>
#define pi 3.141592653589793
using namespace std;

struct point {
  double x, y;
};

double dist(point a, point b) {
  double dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

double area(double a, double b, double c) {
  double s = (a + b + c) * 0.5;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

int main() {
  point a, b, c;
  while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
    double r = rCircumCircle(a, b, c);
    double ans = 2 * pi * r;
    cout << fixed << setprecision(2) << ans << endl;
  }
  return 0;
}
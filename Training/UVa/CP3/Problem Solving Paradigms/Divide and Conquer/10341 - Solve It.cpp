// Bisection Method
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

double p, q, r, s, t, u;

double f(double x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
  while (cin >> p >> q >> r >> s >> t >> u) {
    if (f(0) * f(1) > 0.0) {
      cout << "No solution" << endl;
    } else {
      double lo = 0.0, hi = 1.0;
      while (abs(hi - lo) > EPS) {
        double mid = (hi + lo) / 2.0;
        if (f(lo) * f(mid) > 0.0)
          lo = mid;
        else
          hi = mid;
      }
      cout << fixed << setprecision(4) << lo << endl;
    }
  }
  return 0;
}
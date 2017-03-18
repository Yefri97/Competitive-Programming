#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main() {
  int t; cin >> t;
  while (t--) {
    double l; cin >> l;
    double r = l / 5, Ared = pi * r * r;
    double Agreen = l * (l * 6 / 10) - Ared;
    cout << fixed << setprecision(2) << Ared << " " << Agreen << endl;
  }
  return 0;
}
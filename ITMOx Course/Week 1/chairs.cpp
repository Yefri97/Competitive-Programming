#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("chairs.in");
  ofstream cout("chairs.out");
  double a, b, c; cin >> a >> b >> c;
  double ans = (a + b + c) / 6.0;
  cout << fixed << ans << endl;
  return 0;
}
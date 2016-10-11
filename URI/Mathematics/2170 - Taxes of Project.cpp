#include <bits/stdc++.h>
using namespace std;

int main() {
  int cs = 0;
  double x, y;
  while (cin >> x >> y) {
    cout << "Projeto " << ++cs << ":" << endl;
    double ans = (y - x) / x * 100.0;
    cout << fixed << setprecision(2) << "Percentual dos juros da aplicacao: " << ans << " \%" << endl;
    cout << endl;
  }
  return 0;
}
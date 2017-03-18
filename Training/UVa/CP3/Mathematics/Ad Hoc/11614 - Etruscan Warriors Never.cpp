#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    double k; cin >> k;
    long long ans = (sqrt(8 * k + 1) - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}
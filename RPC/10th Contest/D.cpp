/*
 *  RPC 10-th Contest 2016
 *  Problem D: Divisors
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    int a, b; cin >> a >> b;
    int ans = 0;
    for (int i = 1; i * i <= a; i++) {
      if (a % i == 0) {
        if (i % b != 0) ans += i;
        if (i * i == a) continue;
        if ((a / i) % b != 0) ans += (a / i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

/*
 *  RPC 10-th Contest 2016
 *  Problem E: Laser Mirrors
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int eulerPhi(int n) {
  int ans = n;
  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) ans -= ans / p;
    while (n % p == 0) n /= p;
  }
  if (n != 1) ans -= ans / n;
  return ans;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = eulerPhi(n);
    cout << ans << endl;
  }
  return 0;
}

/*
 *  RPC 11-th Contest 2016
 *  Problem D: Divisors
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, nd, m, nm;
  while (cin >> d >> nd >> m >> nm) {
    vector<int> divisors;
    for (int i = 1; i * i <= m; i++) {
      if (m % i == 0) {
        divisors.push_back(i);
        if (i * i != m) divisors.push_back(m / i);
      }
    }
    sort(divisors.begin(), divisors.end());
    int ans = -1;
    for (int i = 0; ans == -1 && i < divisors.size(); i++) {
      int num = divisors[i];
      if (num % d == 0 && num % nd != 0 && nm % num != 0) ans = num;
    }
    cout << ans << endl;
  }
  return 0;
}
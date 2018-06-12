/*
 *  RPC 04st Contest 2017
 *  Problem B: Ballons
 *  Outcome: Accepted | Category: Easy
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, b;
  while (cin >> n >> b and (n or b)) {
    int acc = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      acc += x;
    }
    int ans = b / acc;
    cout << ans << endl;
  }
  return 0;
}
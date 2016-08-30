/*
 *  RPC 9-th Contest 2016
 *  Problem A: A Constant Struggle
 *  Status: Accepted
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int v[10];
ll memo[110][10];

ll count(int n, int k) {
  if (k == 0) return (n == 0);
  if (memo[n][k] != -1) return memo[n][k];
  ll ans = 0;
  for (int i = 0; v[k - 1] * i <= n; i++) 
    ans += count(n - v[k - 1] * i, k - 1);
  return memo[n][k] = ans;
}

int main() {
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Equation #" << ++cs << ": ";
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < 9; i++) 
      cin >> v[i];
    ll ans = count(v[8], 8);
    cout << ans << endl;
  }
  return 0;
}
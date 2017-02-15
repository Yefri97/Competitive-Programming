/*
 *  RPC 9-th Contest 2016
 *  Problem J: Shopping Spree
 *  Status: Accepted \ DP - Knapsack
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500;
int val[MAX_N + 10], memo[MAX_N + 10][MAX_N + 10];

int solver(int id, int k) {
  if (k == 0) return 0;
  if (id == 0) return val[0];
  if (memo[id][k] != -1) return memo[id][k];
  return memo[id][k] = max(solver(id - 1, k), solver(id - 1, min(k - 1, (id + 1) / 2 - 1)) + val[id]);
}

int main() {
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Spree #" << ++cs << ": ";
    int n; cin >> n;
    for (int i = 0; i < n; i++)
      cin >> val[i];
    memset(memo, -1, sizeof memo);
    int ans = solver(n - 1, n);
    cout << ans << endl;
  }
  return 0;
}
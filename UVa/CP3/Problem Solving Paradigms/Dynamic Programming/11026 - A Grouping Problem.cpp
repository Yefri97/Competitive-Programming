#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1000;
ll m, v[MX + 10], memo[MX + 10][MX + 10];

ll combine(int n, int k) {
  if (k == 0) return 1;
  if (memo[n][k] != -1) return memo[n][k];
  if (n == k) return memo[n][k] = (v[n] * combine(n - 1, k - 1)) % m;
  return memo[n][k] = (v[n] * combine(n - 1, k - 1) + combine(n - 1, k)) % m;
}

int main() {
  int n;
  while (cin >> n >> m && n + m) {
    for (int i = 0; i < n; i++)
      cin >> v[i + 1];
    memset(memo, -1, sizeof memo);
    ll ans = -1;
    for (int i = 1; i <= n; i++)
      ans = max(ans, combine(n, i));
    cout << ans << endl;
  }
  return 0;
}
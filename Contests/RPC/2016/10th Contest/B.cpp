/*
 *  RPC 10-th Contest 2016
 *  Problem B: Subsets
 *  Status: Accepted \ Math
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 500000, MOD = 1e9 + 7;
ll arr[MAX_N + 10];

ll modExp(ll base, ll p) {
  if (p == 0) return 1;
  ll res = modExp(base, p / 2); res = (res * res) % MOD;
  if (p % 2) res = (res * base) % MOD;
  return res % MOD;
}

int main() {
  arr[0] = 1;
  int n; ll p;
  while (cin >> n >> p) {
    for (int i = 1; i <= n; i++) {
      ll x; cin >> x;
      arr[i] = (arr[i - 1] * (modExp(p, x) + 1)) % MOD;
    }
    int q; cin >> q;
    while (q--) {
      int a, b; cin >> a >> b;
      ll xInv = modExp(arr[a - 1], MOD - 2), y = arr[b];
      cout << (y * xInv) % MOD - 1 << endl;
    }
  }
  return 0;
}


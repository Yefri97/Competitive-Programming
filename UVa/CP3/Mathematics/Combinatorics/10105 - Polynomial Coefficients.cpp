#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll fact[15]; fact[0] = fact[1] = 1;
  for (int i = 2; i < 15; i++)
    fact[i] = fact[i - 1] * (ll) i;
  int n, k;
  while (cin >> n >> k) {
    ll ans = fact[n];
    while (k--) {
      int x; cin >> x;
      ans /= fact[x];
    }
    cout << ans << endl;
  }
}
// Iterative (One loop, Linear Scan)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x) { return (sqrt(8 * x + 1) - 1) / 2; }

const int kMX_N = 20;
int n, coef[kMX_N + 10];

ll pol(ll x) {
  ll target = 0, pot = 1;
  for (int i = 0; i < n + 1; i++, pot *= x) {
    target += coef[i] * pot;
  }
  return target;
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n + 1; i++)
      cin >> coef[i];
    int d, k; cin >> d >> k;
    ll x = f((k + d - 1) / d - 1) + 1;
    ll ans = pol(x);
    cout << ans << endl;
  }
  return 0;
}
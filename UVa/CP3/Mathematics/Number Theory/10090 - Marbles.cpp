#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 1e9;
ll x, y, d;

void extendedEuclid(ll a, ll b) {
  if (b == 0) { x = 1; y = 0; d = a; return; }
  extendedEuclid(b, a % b);
  ll x1 = y;
  ll y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}

int main() {
  ll k;
  while (cin >> k && k) {
    ll ca, a, cb, b;
    cin >> ca >> a;
    cin >> cb >> b;
    extendedEuclid(a, b);
    
    ii ans = ii(-1, -1);
    if (k % d == 0) {
      ll low = ceil(-double(x * k) / double(b)), high = floor(double(y * k) / double(a));
      if (low <= high) {
        ll sxa = x * (k / d) + (b / d) * low, sya = y * (k / d) - (a / d) * low;
        ll sxb = x * (k / d) + (b / d) * high, syb = y * (k / d) - (a / d) * high;
        if (ca * sxa + cb * sya < ca * sxb + cb * syb) {
          ans = ii(sxa, sya);
        } else {
          ans = ii(sxb, syb);
        }
      }
    }

    if (ans != ii(-1, -1)) {
      cout << ans.first << " " << ans.second << endl;
    } else {
      cout << "failed" << endl;
    }
  }
  return 0;
}
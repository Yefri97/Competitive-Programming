#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll eulerPhi(ll n) {
  ll ans = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) ans -= ans / i;
    while (n % i == 0) n /= i;
  }
  if (n != 1) ans -= ans / n;
  return ans;
}

ll numDiv(ll n) {
  ll ans = 1;
  for (int i = 2; i * i <= n; i++) {
    int power = 0;
    while (n % i == 0) { n /= i; power++; }
    ans *= (power + 1);
  }
  if (n != 1) ans *= 2;
  return ans;
}

int main() {
  ll n;
  while (cin >> n) {
    ll ans = n - eulerPhi(n) - numDiv(n) + 1;
    cout << ans << endl;
  }
  return 0;
}

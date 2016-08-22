#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> primes;

ll eulerPhi(ll n) {
  ll idx = 0, p = primes[idx], ans = n;
  while (p * p <= n) {
    if (n % p == 0) ans -= ans / p;
    while (n % p == 0) n /= p;
    p = primes[++idx];
  }
  if (n != 1) ans -= ans / n;
  return ans;
}

ll numDiv(ll n) {
  ll idx = 0, p = primes[idx], ans = 1;
  while (p * p <= n) {
    int power = 0;
    while (n % p == 0) { n /= p; power++; }
    ans *= (power + 1);
    p = primes[++idx];
  }
  if (n != 1) ans *= 2;
  return ans;
}

void sieve(int upp) {
  vector<int> v(upp, 1);
  for (int i = 2; i * i <= upp; i++) if (v[i])
    for (int j = i * i; j <= upp; j += i) v[j] = 0;
  for (int i = 2; i <= upp; i++) if (v[i])
    primes.push_back(i);
}

int main() {
  sieve(100000);
  ll n;
  while (cin >> n) {
    ll ans = n - eulerPhi(n) - numDiv(n) + 1;
    cout << ans << endl;
  }
  return 0;
}

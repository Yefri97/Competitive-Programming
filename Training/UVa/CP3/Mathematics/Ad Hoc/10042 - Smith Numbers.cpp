#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primeFactors(ll N) {
  vi factors;
  for (ll p = 2; p * p <= N; p++) {
    while (N % p == 0) { 
      N /= p;
      factors.push_back(p);
    }
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

int sumDig(ll n) {
  int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

int sumDig(vi v) {
  int ans = 0;
  for (int i = 0; i < v.size(); i++)
    ans += sumDig(v[i]);
  return ans;
}

bool check(ll n) {
  vi factors = primeFactors(n);
  return (factors.size() == 1 || sumDig(n) != sumDig(factors));
}

int main() {
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    ll ans = n + 1;
    while (check(ans))
      ans++;
    cout << ans << endl;
  }
  return 0;
}
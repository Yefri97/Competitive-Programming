/*
 *  RPC 04st Contest 2017
 *  Problem L: Lowest Terms Fractions
 *  Outcome: Accepted | Category: Number Theory
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef long long ll;

vi primes;

void sieve(ll upperbound) {
  ll _sieve_size = upperbound + 1;
  bitset<1000010> bs;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
  }
}

ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;
  while (PF * PF <= N) {
    if (N % PF == 0) ans -= ans / PF;
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(4);
  sieve(100000);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    ll totient = EulerPhi(n);
    cout << totient << " " << (double)totient / 2 << endl;
  }
  return 0;
}
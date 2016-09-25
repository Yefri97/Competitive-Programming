#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll MXN = -1;
const int nsieve = 70000;

int main() {
  int sieve[nsieve + 10]; memset(sieve, 1, sizeof sieve);
  for (int i = 2; i * i < nsieve; i++) if (sieve[i])
    for (int j = i * i; j < nsieve; j += i) sieve[j] = 0;

  int isPow[nsieve + 10]; memset(isPow, 0, sizeof isPow);
  for (int i = 2; i * i < nsieve; i++)
    for (int j = i * i; j < nsieve; j *= i) isPow[j] = 1;

  vector<ll> v; v.push_back(1);
  for (ll i = 2; i < nsieve; i++) if (!isPow[i])
    for (ll j = 1, k = i; j * log2(i) < 64; j++, k *= i) if (!sieve[j])
      v.push_back(k);
  sort(v.begin(), v.end());
  
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  
  return 0;
}
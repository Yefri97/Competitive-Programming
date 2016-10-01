#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAX_N = 1e4, MAX_SIEVE = 1e6;

int sieve[MAX_SIEVE + 10], freq[MAX_N + 10];

void init_sieve() {
  memset(sieve, 0, sizeof sieve); sieve[0] = sieve[1] = 1;
  for (int i = 2; i * i <= MAX_SIEVE; i++) if (!sieve[i])
    for (int j = i * i; j <= MAX_SIEVE; j += i) sieve[j] = 1;
}

bool isPrime(int n) {
  if (n <= MAX_SIEVE) return !sieve[n];
  for (int p = 0; p * p < n; p++)
    if (n % p == 0)
      return 0;
  return 1;
}

ii solver(int n) {
  for (int i = 2; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (isPrime(freq[j] - freq[j - i]))
        return ii(i, j - i);
  return ii(-1, -1);
} 

int main() {
  init_sieve();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    freq[0] = 0;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      v[i - 1] = x;
      freq[i] = freq[i - 1] + x;
    }
    ii ans = solver(n);
    int len = ans.first, init = ans.second;
    if (len != -1) {
      cout << "Shortest primed subsequence is length " << len << ":";
      for (int i = 0; i < len; i++)
        cout << " " << v[init + i];
      cout << endl;
    } else {
      cout << "This sequence is anti-primed." << endl;
    }
  }
  return 0;
}
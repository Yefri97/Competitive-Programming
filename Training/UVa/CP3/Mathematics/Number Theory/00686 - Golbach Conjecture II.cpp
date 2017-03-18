#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
vector<int> sieve;

void init_sieve(int n) {
  sieve.assign(n, 1);
  for (int i = 2; i * i <= n; i++) if (sieve[i])
    for (int j = i * i; j <= n; j += i) sieve[j] = 0;
}

int main() {
  init_sieve(MX);
  int n;
  while (cin >> n && n) {
    int ans = 0;
    for (int i = 2; 2 * i <= n; i++)
      if (sieve[i] && sieve[n - i]) ans++;
    cout << ans << endl;
  }
  return 0;
}
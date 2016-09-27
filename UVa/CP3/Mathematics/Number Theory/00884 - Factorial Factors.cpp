#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000;
vector<int> sieve(MAX_N + 10);

void init_sieve() {
  for (int i = 2; i <= MAX_N; i++) if (sieve[i] == 0) {
    for (int j = i; j <= MAX_N; j += i) {
      int k = j;
      while (k % i == 0) { sieve[j]++; k /= i; }
    }
  }
}

int main() {
  init_sieve();
  int ans[MAX_N + 10]; ans[1] = 0;
  for (int i = 2; i <= MAX_N; i++)
    ans[i] = ans[i - 1] + sieve[i];
  int n;
  while (cin >> n) {
    cout << ans[n] << endl;
  }
  return 0;
}
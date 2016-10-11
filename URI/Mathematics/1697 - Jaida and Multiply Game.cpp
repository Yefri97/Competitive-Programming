#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e6;

bitset<MAX_N + 10> sieve;

int main() {
  int t; cin >> t;
  while (t--) {
    sieve.reset();
    int n; cin >> n;
    while (n--) {
      int x; cin >> x;
      if (x < MAX_N)
        sieve[x] = 1;
    }
    int ans = 0;
    if (sieve[1]) {
      for (int i = 2; i <= MAX_N; i++) {
        if (sieve[i]) {
          for (int j = i + i; j <= MAX_N; j += i)
            sieve[j] = 1;
        } else {
          ans = i - 1;
          break;
        }
      }
    }
    cout << ans << endl;
  }
}
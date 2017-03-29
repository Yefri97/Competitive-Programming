// Recursive Backtracking (Medium)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;

int n, ans[MAXN + 5], used[MAXN + 5];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool isPrime(int x) {
  for (int i = 0; i < 11; i++)
    if (primes[i] == x)
      return true;
  return false;
}

void solver(int id) {
  if (id == n) {
    if (!isPrime(ans[id - 1] + 1)) return;
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  } else {
    for (int k = 1; k <= n; k++) {
      if (isPrime(k + ans[id - 1]) and !used[k]) {
        ans[id] = k;
        used[k] = 1;
        solver(id + 1);
        used[k] = 0;
      }
    }
  }
}

int main() {
  int cs = 0;
  memset(used, 0, sizeof used);
  ans[0] = used[1] = 1;
  while (cin >> n) {
    if (cs) cout << endl;
    cout << "Case " << ++cs << ":" << endl;
    solver(1);
  }
  return 0;
}

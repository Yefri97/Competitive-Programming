#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
int mint[MAX_N + 10], done[MAX_N + 10], rlist[MAX_N + 10];

int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      cin >> mint[i];
    for (int i = 0; i < m; i++)
      cin >> rlist[i];
    memset(done, 0, sizeof done);
    int ans = 0, ok = 0, k = n;
    for (int i = 0; ok == 0 && i < m; i++) {
      int x = rlist[i]; x--;
      if (!done[x]) {
        done[x] = 1;
        k--;
      }
      ans += mint[x];
      if (k == 0) ok = 1;
    }
    if (ok) cout << ans << endl;
    else cout << -1 << endl;
  }
  return 0;
}
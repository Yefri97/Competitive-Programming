// Iterative, Two Nested loops
#include <bits/stdc++.h>
using namespace std;

const int kINF = 1e8;

int main() {
  int n, tc = 0;
  while (cin >> n && n) {
    cout << "Case " << ++tc << ":" << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int q; cin >> q;
    while (q--) {
      int m; cin >> m;
      int ans, closest = kINF;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          int x = abs(m - (v[i] + v[j]));
          if (x < closest) {
            closest = x;
            ans = v[i] + v[j];
          }
        }
      }
      cout << "Closest sum to " << m << " is " << ans << "." << endl;
    }
  }
  return 0;
}
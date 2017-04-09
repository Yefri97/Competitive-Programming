// Binary Search
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m and (n or m)) {
    vector< vector<int> > diag((m - 1) + (n - 1) + 1);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      int x; cin >> x;
      diag[m + (i - j) - 1].push_back(x);
    }
    int q; cin >> q;
    while (q--) {
      int ans = 0;
      int l, u; cin >> l >> u;
      for (int i = 0; i < diag.size(); i++) {
        vector<int>::iterator itl, itu;
        itl = lower_bound(diag[i].begin(), diag[i].end(), l);
        itu = upper_bound(diag[i].begin(), diag[i].end(), u);
        ans = max(ans, (int)(itu - itl));
      }
      cout << ans << endl;
    }
    cout << "-" << endl;
  }
  return 0;
}
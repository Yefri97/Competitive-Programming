#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<bool> hole(n);
  for (int i = 0; i < m; i++) {
    int x; cin >> x; x--;
    hole[x] = true;
  }
  int curr = 0;
  bool fall = hole[curr];
  while (k--) {
    int u, v; cin >> u >> v; u--; v--;
    if (!fall and (curr == u or curr == v)) {
      if (curr == u)
        curr = v;
      else
        curr = u;
    }
    fall |= hole[curr];
  }
  cout << curr + 1 << endl;
  return 0;
}
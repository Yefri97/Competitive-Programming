#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> bank(n);
  for (int i = 0; i < n; i++)
    cin >> bank[i];
  int maxval = *(max_element(bank.begin(), bank.end()));
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (bank[i] == maxval) x++;
    else if (bank[i] == maxval - 1) y++;
  }
  vector< vector<int> > g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = maxval + 2;
  for (int u = 0, w; u < n; u++) {
    if (bank[u] == maxval) x--;
    else if (bank[u] == maxval - 1) y--;

    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (bank[v] == maxval) x--, y++;
      else if (bank[v] == maxval - 1) y--;
    }

    if (x == 0) {
      ans = min(ans, maxval + 1);
      if (y == 0) ans = min(ans, maxval);
    }

    if (bank[u] == maxval) x++;
    else if (bank[u] == maxval - 1) y++;

    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (bank[v] == maxval) x++, y--;
      else if (bank[v] == maxval - 1) y++;
    }
  }
  cout << ans << endl;
  return 0;
}
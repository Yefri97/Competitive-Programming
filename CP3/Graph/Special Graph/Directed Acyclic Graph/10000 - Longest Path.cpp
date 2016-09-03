#include <bits/stdc++.h>
using namespace std;

const int MX = 100, INF = 1000;

vector< vector<int> > g;
int memo[MX + 10][MX + 10];

int longestPath(int u, int t) {
  if (u == t) return 0;
  if (memo[u][t] != -1) return memo[u][t];
  int ans = -INF;
  for (int i = 0; i < g[u].size(); i++)
    ans = max(ans, longestPath(g[u][i], t) + 1);
  return memo[u][t] = ans;
}

int main() {
  int n, cs = 0;
  while (cin >> n && n) {
    g.clear(); g.resize(n);
    memset(memo, -1, sizeof memo);
    int s; cin >> s; s--;
    int a, b;
    while (cin >> a >> b && a + b) {
      a--; b--;
      g[a].push_back(b);
    }
    int ans = -1, far = INF;
    for (int i = 0; i < n; i++) {
      int lp = longestPath(s, i);
      if (ans <= lp) {
        far = (ans == lp)? min(far, i) : i;
        ans = lp;
      }
    }
    cout << "Case " << ++cs << ": The longest path from " << s + 1 << " has length " << ans << ", finishing at " << far + 1 << "." << endl;
    cout << endl;
  }
  return 0;
}
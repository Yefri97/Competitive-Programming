#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;

bool check_bipartite(int s) {
  queue<int> q; q.push(s);
  vector<int> color(g.size(), -1); color[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (color[v] == -1) {
        color[v] = 1 - color[u];
        q.push(v);
      } else if (color[v] == color[u]) return false;
    }
  }
  return true;
}

int main() {
  int n;
  while (cin >> n && n) {
    g.clear(); g.resize(n);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    bool ans = check_bipartite(0);
    if (ans) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
  }
  return 0;
}
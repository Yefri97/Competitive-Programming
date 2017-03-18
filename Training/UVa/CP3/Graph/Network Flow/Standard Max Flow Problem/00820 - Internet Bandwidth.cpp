#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MX = 100, INF = 1e7;
int res[MX + 10][MX + 10], s, t, f;
vi p;

void augment(int v, int minEdge) {
  if (v == s) { f = minEdge; return; }
  else if (p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}

int main() {
  int n, cs = 0;
  while (cin >> n && n) {
    int m; cin >> s >> t >> m; s--; t--;
    memset(res, 0, sizeof res);
    while (m--) {
      int a, b, cap; cin >> a >> b >> cap; a--; b--;
      res[a][b] += cap;
      res[b][a] += cap;
    }
    int mf = 0;
    while (1) {
      f = 0;
      vi dist(n, INF); dist[s] = 0;
      queue<int> q; q.push(s);
      p.assign(n, -1);
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int v = 0; v < n; v++) {
          if (res[u][v] > 0 && dist[v] == INF) {
            dist[v] = dist[u] + 1;
            q.push(v);
            p[v] = u;
          }
        }
      }
      augment(t, INF);
      if (f == 0) break;
      mf += f;
    }
    cout << "Network " << ++cs << endl;
    cout << "The bandwidth is " << mf << "." << endl << endl;
  }
  return 0;
}
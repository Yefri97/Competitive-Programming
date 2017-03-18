#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi airp;
vector<vi> g;
const int MX = 2000, INF = -1;

int sssp(int s, int t) {
  if (s == t) return 0;
  vi dist(MX, INF); dist[s] = (airp[s])? 0 : 1;
  deque<int> dq; dq.push_front(s);
  while (!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    if (u == t) return dist[u];
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (dist[v] == INF) {
        if (airp[v]) {
          dist[v] = dist[u];
          dq.push_front(v);
        } else {
          dist[v] = dist[u] + 1;
          dq.push_back(v);
        }
      }
    }
  }
  return -1;
}

int main() {
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Case " << ++cs << ":" << endl;
    int n, m, k; cin >> n >> m >> k;
    airp.assign(n, 0);
    while (k--) {
      int x; cin >> x; x--;
      airp[x] = 1;
    }
    g.clear(); g.resize(n);
    while (m--) {
      int a, b; cin >> a >> b; a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int q; cin >> q;
    while (q--) {
      int a, b; cin >> a >> b; a--; b--;
      int ans = sssp(a, b);
      cout << ans << endl;
    }
    cout << endl;
  }
  return 0;
}
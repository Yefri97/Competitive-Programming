/*
 *  ACM ICPC XXX Colombian Programming Contest 2016
 *  Problem K: Bank Robbery
 *  Status: Accepted \ Dijkstra
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int INF = 1e9;
int V;
vector< vector<ii> > g;

vector<int> solver(int s) {
  vector<int> dist(V, INF); dist[s] = 0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < g[u].size(); j++) {
      ii v = g[u][j];
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
  return dist;
}

int main() {
  int n, m, b, p;
  while (cin >> n >> m >> b >> p) {
    V = n + 1;
    g.clear(); g.resize(V);
    for (int i = 0; i < m; i++) {
      int a, b, w; cin >> a >> b >> w;
      g[a].push_back(ii(b, w));
      g[b].push_back(ii(a, w));
    }

    vector<int> banks(b);
    for (int i = 0; i < b; i++)
      cin >> banks[i];

    for (int i = 0; i < p; i++) {
      int id; cin >> id;
      g[n].push_back(ii(id, 0));
    }

    vector<int> dist = solver(n);

    int ans = -1;
    for (int i = 0; i < banks.size(); i++)
      ans = max(ans, dist[banks[i]]);

    int cont = 0;
    for (int i = 0; i < banks.size(); i++)
      if (dist[banks[i]] == ans) cont++;
    
    cout << cont << " ";
    if (ans == INF) cout << "*";
    else cout << ans;
    cout << endl;

    sort(banks.begin(), banks.end());
    int first = 1;
    for (int i = 0; i < banks.size(); i++) if (dist[banks[i]] == ans) {
      if (!first) cout << " "; first = 0;
      cout << banks[i];
    }
    cout << endl;

  }
  return 0;
}
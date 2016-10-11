#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e7;
int n, numSCC;
vi setSCC, S, visited;
vector<vii> graph, graphT;

int Dijkstra(int s, int t) {
  vi dist(n, INF); dist[s] = 0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < graph[u].size(); j++) {
      ii v = graph[u][j];
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
  return dist[t];
}

void Kosaraju(int u, int pass) {
  if (pass == 2) setSCC[u] = numSCC;
  visited[u] = 1;
  vii neighbor;
  if (pass == 1) neighbor = graph[u];
  else neighbor = graphT[u];
  for (int i = 0; i < neighbor.size(); i++) {
    ii v = neighbor[i];
    if (!visited[v.first])
      Kosaraju(v.first, pass);
  }
  S.push_back(u);
}

int main() {
  int e;
  while (cin >> n >> e && n + e) {
    graph.clear(); graph.resize(n);
    graphT.clear(); graphT.resize(n);
    while (e--) {
      int a, b, h; cin >> a >> b >> h; a--; b--;
      graph[a].push_back(ii(b, h));
      graphT[b].push_back(ii(a, h));
    }

    S.clear();
    setSCC.assign(n, -1);
    visited.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (!visited[i])
        Kosaraju(i, 1);
    visited.assign(n, 0);
    numSCC = 0;
    for (int i = n - 1; i >= 0; i--)
      if (!visited[S[i]]) {
        numSCC++;
        Kosaraju(S[i], 2);
      }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < graph[i].size(); j++)
        if (setSCC[i] == setSCC[graph[i][j].first])
          graph[i][j].second = 0;

    int q; cin >> q;
    while (q--) {
      int a, b; cin >> a >> b; a--; b--;
      int ans = Dijkstra(a, b);
      if (ans == INF) cout << "Nao e possivel entregar a carta" << endl;
      else cout << ans << endl;
    }
    cout << endl;
  }
}
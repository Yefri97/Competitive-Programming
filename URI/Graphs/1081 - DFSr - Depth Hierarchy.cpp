#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
int n, graph[MAX_N + 10][MAX_N + 10], visited[MAX_N + 10];

void dfs(int u, int k) {
  visited[u] = 1;
  string spaces(k, ' ');
  for (int v = 0; v < n; v++) {
    if (graph[u][v]) {
      cout << spaces << u << "-" << v;
      if (!visited[v]) {
        cout << " pathR(G," << v << ")" << endl;
        dfs(v, k + 2);
      } else {
        cout << endl;
      }
    }
  }
}

int main() {
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Caso " << ++cs << ":" << endl;
    int m, p[MAX_N + 10]; cin >> n >> m;
    memset(p, 0, sizeof p);
    memset(graph, 0, sizeof graph);
    memset(visited, 0, sizeof visited);
    while (m--) {
      int a, b; cin >> a >> b;
      graph[a][b] = 1;
      p[a] = 1;
    }
    for (int i = 0; i < n; i++) if (!visited[i] && p[i]) {
      dfs(i, 2);
      cout << endl;
    }
  }
}
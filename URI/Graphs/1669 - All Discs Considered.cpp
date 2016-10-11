#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAX_N = 100000;

int n1, n2, V, degree[MAX_N + 10];
vector< vi > g;

int topoSort(deque<int> dq) {
  int td[V + 10]; memcpy(td, degree, V * sizeof(int));
  int target = 1, color = (dq.front() < n1);
  while (!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    if ((u < n1) && !color || !(u < n1) && color) { target++; color = u < n1; } 
    //cout << u << " " << target << endl;
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      td[v]--;
      if (td[v] == 0) {
        if ((u < n1 && v < n1) || (!(u < n1) && !(v < n1)))
          dq.push_front(v);
        else
          dq.push_back(v);
      }
    }
  }
  return target;
}

int solver() {
  deque<int> dq_white, dq_black;
  for (int i = 0; i < V; i++) if (degree[i] == 0) {
    dq_white.push_front(i);
    dq_black.push_back(i);
  }
  int a = topoSort(dq_white), b = topoSort(dq_black);
  //cout << a << " " << b << endl;
  return min(a, b);
}

int main() {
  int d;
  while (cin >> n1 >> n2 >> d && (n1 + n2 + d)) {
    V = n1 + n2;
    memset(degree, 0, sizeof degree);
    g.clear(); g.resize(V);
    while (d--) {
      int a, b; cin >> a >> b; a--; b--;
      g[b].push_back(a);
      degree[a]++;
    }
    int ans = solver();
    cout << ans + 1 << endl;
  }  
}
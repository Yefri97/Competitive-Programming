// Recursive Backtracking (Harder)
#include <bits/stdc++.h>
using namespace std;

const int BLACK = 0, WHITE = 1;

int n, best;
vector<int> ans, mis, color;
vector< vector<int> > adjList;

bool check(int u) {
  for (int i = 0; i < adjList[u].size(); i++)
    if (color[adjList[u][i]] == BLACK) 
      return false;
  return true;
}

void solver(int id, int curr) {
  if (id == n) {
    if (curr > best) {
      best = curr;
      ans = mis;
    }
  } else {
    if (check(id)) {
      color[id] = BLACK;
      mis.push_back(id);
      solver(id + 1, curr + 1);
      color[id] = WHITE;
      mis.pop_back();
    }
    solver(id + 1, curr);
  }
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int m; cin >> n >> m;
    adjList.assign(n, vector<int>());
    while (m--) {
      int a, b; cin >> a >> b; a--; b--;
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    best = 0;
    color.assign(n, WHITE);
    solver(0, 0);
    cout << best << endl;
    for (int i = 0; i < ans.size(); i++) {
      if (i) cout << " ";
      cout << ans[i] + 1;
    }
    cout << endl;
  }
  return 0;
}
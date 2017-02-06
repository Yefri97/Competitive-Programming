// Graph Data Structures
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

int main() {
  int n, q; 
  while (cin >> n >> q) {
    vector< vector<int> > adjList(MAXN);
    for (int i = 0; i < n; i++) {
      int x; cin >> x; x--;
      adjList[x].push_back(i+1);
    }
    while (q--) {
      int k, v; cin >> k >> v; k--; v--;
      int ans = (k >= adjList[v].size())? 0 : adjList[v][k];
      cout << ans << endl;
    }
  }
  return 0;
}
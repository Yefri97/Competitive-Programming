#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
int color[30];

void flood_fill(int u, int c) {
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (color[v] == -1) {
      color[v] = c;
      flood_fill(v, c);
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    char cn; cin >> cn;
    cin.ignore();
    int n = cn - 'A' + 1;
    g.clear(); g.resize(n);
    string line;
    while (getline(cin, line) && line.size()) {
      int a = line[0] - 'A', b = line[1] - 'A';
      g[a].push_back(b);
      g[b].push_back(a);
    }
    memset(color, -1, sizeof color);
    int ans = 0;
    for (int i = 0; i < g.size(); i++) if (color[i] == -1) {
      flood_fill(i, 1);
      ans++;
    }
    cout << ans << endl;
    if (t) cout << endl;
  }
  return 0;
}
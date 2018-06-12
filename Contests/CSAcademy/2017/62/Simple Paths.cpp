#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int MX = 1000;

int dfsNC;
int visited[MX], dfs_low[MX], dfs_num[MX], dfs_parent[MX];
vector<int> g1[MX], g2[MX];

void find_bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfsNC++;
    for (int i = 0; i < (int)g1[u].size(); i++) {
        int v = g1[u][i];
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            find_bridges(v);
            if (dfs_low[v] > dfs_num[u]) {
                g2[u].push_back(v);
                g2[v].push_back(u);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int dfs(int u, int t) {
    if (u == t) return 1;
    visited[u] = 1;
    for (int i = 0; i < (int)g2[u].size(); i++) {
        int v = g2[u][i];
        if (visited[v]) continue;
        if (dfs(v, t)) return 1;
    }
    return 0;
}

int main() {
    int n, m, q; cin >> n >> m >> q;
    while (m--) {
        int u, v; cin >> u >> v; u--; v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    dfsNC = 0;
    memset(dfs_num, -1, sizeof dfs_num);
    for (int i = 0; i < n; i++)
        if (dfs_num[i] == -1)
            find_bridges(i);
    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        memset(visited, 0, sizeof visited);
        cout << dfs(u, v) << endl;
    }
    return 0;
}
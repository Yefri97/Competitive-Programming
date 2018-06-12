#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MX = 1e5;

int ans[MX], id[MX];
ll val[MX];
vector<ii> g[MX];
set<ll> dict[MX];

void precalculate(int u, int p, ll acc) {
    val[u] += acc;
    for (auto v : g[u]) {
        if (v.first == p) continue;
        precalculate(v.first, u, acc + v.second);
    }
}

void dfs(int u, int p) {
    int max_size = 0, children_id = u;
    for (auto v : g[u]) {
        if (v.first == p) continue;
        dfs(v.first, u);
        int sz = dict[id[v.first]].size();
        if (sz > max_size) {
            max_size = sz;
            children_id = v.first;
        }
    }
    id[u] = id[children_id];
    for (auto v : g[u]) {
        if (v.first == p || v.first == children_id) continue;
        for (auto d : dict[id[v.first]])
            dict[id[u]].insert(d);
    }
    dict[id[u]].insert(val[u]);
    ans[u] = dict[id[u]].size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(ii(v, w));
        g[v].push_back(ii(u, w));
    }
    for (int i = 0; i < n; i++)
        cin >> val[i];
    precalculate(0, -1, 0);
    for (int i = 0; i < n; i++)
        id[i] = i;
    dfs(0, -1);
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010;

int k;
string s;
vector<string> ans;

ii edges[MN];
vi g[MN], g2[MN], depth[MN];

void dfs(int d, int id) {
	if (SZ(depth[d]) == 0) {
		ans.push_back(s);
		k--;
		return;
	}
	if (SZ(depth[d]) == id) {
		dfs(d + 1, 0);
		return;
	}
	for (int e : g2[depth[d][id]]) {
		s[e] = '1';
		dfs(d, id + 1);
		if (k == 0) return;
		s[e] = '0';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m >> k;
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		edges[i] = ii(u, v);
		g[u].push_back(i);
		g[v].push_back(i);
	}
	vi dist(n, oo);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e : g[u]) {
			int v = edges[e].first + edges[e].second - u;
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	fori(u, 0, n)
		depth[dist[u]].push_back(u);
	fori(i, 0, m) {
		ii e = edges[i];
		if (dist[e.first] + 1 == dist[e.second])
			g2[e.second].push_back(i);
		if (dist[e.second] + 1 == dist[e.first])
			g2[e.first].push_back(i);
	}
	s.assign(m, '0');
	dfs(1, 0);
	cout << ans.size() << endl;
	for (string x : ans)
		cout << x << endl;
	return 0;
}

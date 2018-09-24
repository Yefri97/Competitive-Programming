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

set<int> g[MN];
queue<int> qs[MN];

void dfs(int u, int d) {
	while (!qs[d].empty()) {
		int v = qs[d].front();
		if (g[u].count(v) == 0) break;
		qs[d].pop();
		dfs(v, d + 1);
	}
}

int solve() {
	int n; cin >> n;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	queue<int> q; q.push(0);
	vi dist(n, oo); dist[0] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	if (a[0] != 1) return 0;
	fori(i, 1, n)
		if (dist[a[i] - 1] < dist[a[i - 1] - 1])
			return 0;
	fori(i, 0, n)
		qs[dist[a[i] - 1]].push(a[i] - 1);
	dfs(0, 1);
	fori(i, 1, n)
		if (!qs[i].empty())
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int ans = solve();
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

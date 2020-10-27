#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll oo = 1e15;

int n;
vector<vii> g;
vector<ll> dist;
vector<bool> neg;

void dfs(int u) {
	neg[u] = 1;
	for (int i = 0; i < SZ(g[u]); i++) {
		ii v = g[u][i];
		if (!neg[v.first])
			dfs(v.first);
	}
}

void bellmanFord(int s) {
	dist.assign(n, oo); dist[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			if (dist[u] == oo) continue;
			for (int j = 0; j < SZ(g[u]); j++) {
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
					dist[v.first] = max(-oo, dist[u] + v.second);
			}
		}
	}
	neg.assign(n, false);
	for (int u = 0; u < n; u++) {
		for (int i = 0; i < SZ(g[u]); i++) {
			ii v = g[u][i];
			if (!neg[v.first] && dist[u] < oo && dist[v.first] > dist[u] + v.second)
				dfs(v.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int m; cin >> n >> m;
	g.assign(n, vii());
	fori(i, 0, m) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		int cost; cin >> cost;
		g[u].push_back(ii(v, -cost));
	}
	bellmanFord(0);
	if (neg[n - 1]) {
		cout << -1 << endl;
	} else {
		cout << -dist[n - 1] << endl;
	}
	return 0;
}

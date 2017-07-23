#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 210;

int n;
int A[mxn];
vii g[mxn];
vector<int> dist;
vector<bool> neg;

void dfs(int u) {
	neg[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		ii v = g[u][i];
		if (!neg[v.first])
			dfs(v.first);
	}
}

void bellmanFord(int s) {
	if (n == 0) return;
	dist.assign(n, oo); dist[s] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			if (dist[u] == oo) continue;
			for (int j = 0; j < g[u].size(); j++) {
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
					dist[v.first] = max(-oo, dist[u] + v.second);
			}
		}
	}

	neg.assign(n, false);
	for (int u = 0; u < n; u++)
		for (int i = 0; i < g[u].size(); i++) {
			ii v = g[u][i];
			if (!neg[v.first] && dist[u] < oo && dist[v.first] > dist[u] + v.second)
				dfs(v.first);
		}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	while (cin >> n) {
		fori(i, 0, n) g[i].clear();
		fori(i, 0, n)
			cin >> A[i];
		int m; cin >> m;
		while (m--) {
			int a, b; cin >> a >> b; a--; b--;
			int w = A[b] - A[a];
			g[a].push_back(ii(b, w * w * w));
		}

		bellmanFord(0);

		cout << "Set #" << ++cs << endl;
		int q; cin >> q;
		while (q--) {
			int u; cin >> u; u--;
			if (dist[u] < 3 || neg[u] || dist[u] == oo)
				cout << "?" << endl;
			else
				cout << dist[u] << endl;
		}
	}
	return 0;
}
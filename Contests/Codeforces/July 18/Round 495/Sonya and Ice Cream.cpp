#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

vector<ii> g[MN];

int can(int x, int n, int k) {
	int cnt = n;
	vi dist(n), deg(n), del(n);
	queue<int> q;
	fori(i, 0, n) {
		deg[i] = g[i].size();
		if (deg[i] == 1)
			q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ii par;
		for (ii e : g[u]) {
			if (!del[e.first])
				par = e;
		}
		if (dist[u] + par.second <= x) {
			del[u] = 1;
			cnt--;
			if (cnt == 0) break;
			deg[par.first]--;
			if (deg[par.first] == 1)
				q.push(par.first);
			dist[par.first] = max(dist[par.first], dist[u] + par.second);
		}
	}
	int t = 0;
	fori(i, 0, n) if (!del[i])
		t += (deg[i] > 2);
	return t == 0 && cnt <= k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n - 1) {
		int u, v, d; cin >> u >> v >> d; u--; v--;
		g[u].push_back(ii(v, d));
		g[v].push_back(ii(u, d));
	}
	int lo = -1, hi = oo;
	while (hi - lo > 1) {
		int mi = (lo + hi) / 2;
		if (can(mi, n, k))
			hi = mi;
		else
			lo = mi;
	}
	cout << hi << endl;
	return 0;
}

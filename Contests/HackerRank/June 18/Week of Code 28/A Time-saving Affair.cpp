#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MN = 10010;

vii g[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k, m; cin >> n >> k >> m;
	fori(i, 0, m) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, 0));
	vi dist(n, oo); dist[0] = 0;
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int u = front.second, d = front.first;
		if (d > dist[u]) continue;
		for (ii nxt : g[u]) {
			int v = nxt.first;
			int w = nxt.second;
			if ((dist[u] / k) % 2) 
				w += (dist[u] / k + 1) * k - dist[u];
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
	cout << dist[n - 1] << endl;
	return 0;
}

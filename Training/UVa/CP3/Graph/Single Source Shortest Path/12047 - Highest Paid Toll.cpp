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

const int oo = 1e9;

vi dijkstra(int s, vector<vii> &g) {
	vi dist(g.size(), oo); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		fori(i, 0, g[u].size()) {
			ii v = g[u][i];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, s, t, p; cin >> n >> m >> s >> t >> p; s--, t--;
		vi from(m), to(m), weight(m);
		vector<vii> g(n), g2(n);
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w; u--, v--;
			from[i] = u; to[i] = v; weight[i] = w;
			g[u].push_back(ii(v, w));
			g2[v].push_back(ii(u, w));
		}
		vi dist_source = dijkstra(s, g);
		vi dist_target = dijkstra(t, g2);
		int ans = -1;
		fori(i, 0, m)
			if (dist_source[from[i]] + weight[i] + dist_target[to[i]] <= p)
				ans = max(ans, weight[i]);
		cout << ans << endl;
	}
	return 0;
}
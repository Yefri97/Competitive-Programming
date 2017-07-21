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

const int oo = 1e9, mxn = 20010;

int n;
vii g[mxn];

int dijkstra(int s, int t) {
	vi dist(n, oo); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int u = front.second, d = front.first;
		if (u == t) return dist[u];
		if (d > dist[u]) continue;
		fori(i, 0, g[u].size()) {
			ii v = g[u][i];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int m, s, t; cin >> n >> m >> s >> t;
		fori(i, 0, n) g[i].clear();
		while (m--) {
			int a, b, w; cin >> a >> b >> w;
			g[a].push_back(ii(b, w));
			g[b].push_back(ii(a, w));
		}
		int ans = dijkstra(s, t);
		cout << "Case #" << ++cs << ": ";
		if (ans == -1)
			cout << "unreachable" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
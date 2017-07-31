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

const int oo = 1e9, mxn = 100010;

int dist[mxn], p[mxn];
vi g[mxn], don;

int bfs() {
	memset(dist, -1, sizeof dist);
	queue<int> q;
	fori(i, 0, don.size()) {
		dist[don[i]] = 0;
		q.push(don[i]);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (dist[v] == -1) {
				p[v] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			} else if (p[u] != v) {
				return dist[u];
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fori(i, 0, k) {
		int x; cin >> x; x--;
		don.push_back(x);
	}
	int r = bfs();
	int ans = 0;
	fori(i, 0, n)
		ans += (dist[i] != -1 && dist[i] <= r);
	cout << ans << endl;
	return 0;
}
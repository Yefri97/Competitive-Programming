#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 30;

int n;
int dist[mxn];
vi g[mxn], bfstree[mxn];

int bfs(int s) {
	int last;
	memset(dist, -1, sizeof dist); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		last = u;
		fori(i, 0, bfstree[u].size()) {
			int v = bfstree[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return last;
}

int calc(int sa, int sb) {
	fori(i, 0, n) bfstree[i].clear();
	vi taken(n); taken[sa] = 1;
	queue<int> q; q.push(sa);
	if (sb != -1) {
		taken[sb] = 1;
		bfstree[sa].push_back(sb);
		bfstree[sb].push_back(sa);
		q.push(sb);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (!taken[v]) {
				taken[v] = 1;
				bfstree[u].push_back(v);
				bfstree[v].push_back(u);
				q.push(v);
			}
		}
	}
	int a = bfs(0);
	int b = bfs(a);
	return dist[b];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int m; cin >> n >> m;
		fori(i, 0, n) g[i].clear();
		while (m--) {
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = oo;
		fori(i, 0, n) {
			ans = min(ans, calc(i, -1));
			fori(j, 0, g[i].size())
				ans = min(ans, calc(i, g[i][j]));
		}
		cout << "Case #" << ++cs << ":" << endl;
		cout << ans << endl;
		cout << endl;
	}
	return 0;
}
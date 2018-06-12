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

const int oo = 1e9, mxn = 300010;

int n;
vi dist, g[mxn];

int bfs(int u) {
	dist.assign(n, oo); dist[u] = 0;
	queue<int> q; q.push(u);
	int last = -1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		last = u;
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (dist[v] == oo) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return last;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int a = bfs(0);
	int b = bfs(a);
	cout << dist[b] / 2 + 1 << endl;
	return 0;
}
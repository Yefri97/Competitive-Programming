#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1010;

vi g[MN];

void bfs(int s, vi &dist) {
	int n = dist.size();
	dist.assign(n, -1); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, s, t; cin >> n >> m >> s >> t; s--; t--;

	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vi a(n), b(n);
	bfs(s, a);
	bfs(t, b);

	int ans = 0;
	fori(i, 0, n)
		fori(j, 0, i)
			ans += (min(a[i] + b[j] + 1, b[i] + a[j] + 1) >= a[t]);

	cout << ans - m << endl;

	return 0;
}

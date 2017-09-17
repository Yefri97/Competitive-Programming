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

const int oo = 1e9, mxn = 5000;

int dist[mxn], p[mxn];
vi g[mxn];

int bfs(int s) {
	int last;
	memset(dist, -1, sizeof dist); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		last = u;
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				p[v] = u;
				q.push(v);
			}
		}
	}
	return last;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		fori(i, 0, n) g[i].clear();
		fori(u, 0, n) {
			int k; cin >> k;
			while (k--) {
				int v; cin >> v; v--;
				g[u].push_back(v);
			}
		}
		int a = bfs(0);
		int b = bfs(a);
		int d = dist[b];
		int u = b;
		fori(i, 0, d / 2) u = p[u];
		ii best = ii(u + 1, -1);
		if (d & 1) best.second = p[u] + 1;
		// BEST
		cout << "Best Roots  : ";
		if (best.second == -1) cout << best.first << endl;
		else cout << min(best.first, best.second) << " " << max(best.first, best.second) << endl;
		// WORST
		set<int> worst;
		fori(i, 0, n)
			if (dist[i] == d)
				worst.insert(i);
		bfs(b);
		fori(i, 0, n)
			if (dist[i] == d)
				worst.insert(i);
		cout << "Worst Roots :";
		for (int x : worst)
			cout << " " << x + 1;
		cout << endl;
	}
	return 0;
}
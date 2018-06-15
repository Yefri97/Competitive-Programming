#include <bits/stdc++.h>
// #define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

vi g[MN];
priority_queue<int> pq[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k, s; cin >> n >> m >> k >> s;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fori(j, 0, k) {
		vi dist(n, oo);
		queue<int> q;
		fori(i, 0, n) if (a[i] == j + 1) {
			q.push(i);
			dist[i] = 0;
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : g[u]) {
				if (dist[u] + 1 < dist[v]) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		fori(i, 0, n) {
			pq[i].push(dist[i]);
			if (pq[i].size() > s) pq[i].pop();
		}
	}
	fori(i, 0, n) {
		int ans = 0;
		while (!pq[i].empty())
			ans += pq[i].top(), pq[i].pop();
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}

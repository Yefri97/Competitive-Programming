#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int oo = 1e9, MX = 10000;

int nn;
vii g1[MX];
int g2[10][10];
int dist[10][MX];
int memo[10][(1 << 10)];

int tsp(int pos, int mask) {
	if (mask == (1 << nn) - 1)
		return memo[pos][mask] = g2[pos][0];
	if (memo[pos][mask] != -1) return memo[pos][mask];
	int ans = oo;
	fori(i, 0, nn)
		if (i != pos && (mask & (1 << i)) == 0)
			ans = min(ans, g2[pos][i] + tsp(i, mask | (1 << i)));
	return memo[pos][mask] = ans;
}

void sssp(int id, int s) {
	dist[id][s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii top = pq.top(); pq.pop();
		int d = top.first, u = top.second;
		if (d > dist[id][u]) continue;
		for (auto v : g1[u]) {
			if (dist[id][v.first] > dist[id][u] + v.second) {
				dist[id][v.first] = dist[id][u] + v.second;
				pq.push(ii(dist[id][v.first], v.first));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, n) g1[i].clear();
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w;
			g1[u].push_back(ii(v, w));
			g1[v].push_back(ii(u, w));
		}

		int k; cin >> k;
		vi idols(k);
		fori(i, 0, k)
			cin >> idols[i];

		int limit; cin >> limit;

		fori(i, 0, k + 1)
			fori(j, 0, n)
				dist[i][j] = oo;

		sssp(0, 0);

		vi reachables;

		fori(i, 0, k)
			if (dist[0][idols[i]] < oo)
				reachables.push_back(idols[i]);

		int kk = reachables.size();

		fori(i, 0, kk)
			sssp(i + 1, reachables[i]);

		memset(g2, 0, sizeof g2);

		for (int i = 1; i <= kk; i++)
			g2[0][i] = g2[i][0] = dist[0][reachables[i - 1]];

		for (int i = 1; i <= kk; i++)
			for (int j = 1; j <= kk; j++)
				g2[i][j] = g2[j][i] = dist[i][reachables[j - 1]];

		memset(memo, -1, sizeof memo);
		nn = kk + 1;
		tsp(0, 1);

		int ans = 0;

		for (int i = 0; i < (1 << nn); i++) {
			for (int j = 0; j < nn; j++) {
				int bit = i ^ ((1 << nn) - 1);
				bit |= (1 << 0);
				bit |= (1 << j);
				if (tsp(j, bit) + g2[j][0] <= limit)
					ans = max(ans, __builtin_popcount(i) - 1);
			}
		}

		cout << ans << endl;

	}
	return 0;
}
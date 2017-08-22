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

const int oo = 1e9, mxn = 60;

int dist[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int nc, cs = 0;
	while (cin >> nc && nc) {
		int n = 0;
		map<int, int> mapper;
		fori(i, 0, mxn) fori(j, 0, mxn) dist[i][j] = (i == j ? 0 : oo);
		while (nc--) {
			int a, b; cin >> a >> b;
			if (mapper.count(a) == 0) mapper[a] = n++;
			if (mapper.count(b) == 0) mapper[b] = n++;
			int u = mapper[a], v = mapper[b];
			if (u == v) continue;
			dist[u][v] = 1;
			dist[v][u] = 1;
		}
		fori(k, 0, n)
			fori(i, 0, n)
				fori(j, 0, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int s, ttl;
		while (cin >> s >> ttl && s) {
			int ns = mapper[s], ans = 0;
			fori(i, 0, n)
				ans += (dist[ns][i] > ttl);
			cout << "Case " << ++cs << ": " << ans << " nodes not reachable from node " << s << " with TTL = " << ttl << "." << endl;
		}
	}
	return 0;
}
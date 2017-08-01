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

const int oo = 1e9, mxn = 110;

int dist[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n)
			fori(j, 0, n)
				dist[i][j] = (i == j ? 0 : oo);
		int r; cin >> r;
		while (r--) {
			int u, v; cin >> u >> v;
			dist[u][v] = dist[v][u] = 1;
		}
		int s, t; cin >> s >> t;
		fori(k, 0, n)
			fori(i, 0, n)
				fori(j, 0, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int ans = 0;
		fori(i, 0, n)
			ans = max(ans, dist[s][i] + dist[i][t]);
		cout << "Case " << ++cs << ": " << ans << endl;
	}
	return 0;
}
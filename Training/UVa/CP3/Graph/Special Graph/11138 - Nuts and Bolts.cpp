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

const int oo = 1e9, mxn = 500;

vi match, vis, g[2 * mxn];

int aug(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (match[v] == -1 || aug(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, n + m) g[i].clear();
		fori(i, 0, n) {
			fori(j, 0, m) {
				int x; cin >> x;
				if (x == 0) continue;
				g[i].push_back(n + j);
				g[n + j].push_back(i);
			}
		}
		int mcbm = 0;
		match.assign(n + m, -1);
		fori(u, 0, n) {
			vis.assign(n, 0);
			mcbm += aug(u);
		}
		cout << "Case " << ++cs << ": a maximum of " << mcbm << " nuts and bolts can be fitted together" << endl;
	}
	return 0;
}
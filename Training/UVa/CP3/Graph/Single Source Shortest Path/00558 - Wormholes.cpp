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

const int oo = 1e9, mxn = 1010;

vii g[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, n) g[i].clear();
		fori(i, 0, m) {
			int a, b, w; cin >> a >> b >> w;
			g[a].push_back(ii(b, w));
		}
		// Bellmand Ford
		vi dist(n, oo);
		fori(i, 0, n - 1) {
			fori(u, 0, n) {
				fori(j, 0, g[u].size()) {
					ii v = g[u][j];
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				}
			}
		}
		bool ans = false;
		fori(u, 0, n) {
			fori(j, 0, g[u].size()) {
				ii v = g[u][j];
				if (dist[u] + v.second < dist[v.first])
					ans = true;
			}
		}
		cout << (ans ? "possible" : "not possible") << endl;
	}
	return 0;
}
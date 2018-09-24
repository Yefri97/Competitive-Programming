#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int dist[100][100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		fori(i, 0, n)
			fori(j, 0, n)
				dist[i][j] = (i != j ? oo : 0);
		fori(i, 0, m) {
			int u, v, w; cin >> u >> v >> w;
			dist[u][v] = dist[v][u] = w;
		}
		int mn = oo;
		fori(i, 0, 3) {
			int s; cin >> s;
			mn = min(mn, s);
		}
		fori(k, 0, n)
			fori(i, 0, n)
				fori(j, 0, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int mx = 0;
		fori(i, 0, n)
			fori(j, 0, n)
				mx = max(mx, dist[i][j]);
		cout << (mx + mn - 1) / mn << endl;
	}
	return 0;
}

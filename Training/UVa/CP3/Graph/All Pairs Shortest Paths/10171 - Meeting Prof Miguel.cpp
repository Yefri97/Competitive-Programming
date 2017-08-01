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

const int oo = 1e9, mxn = 26;

int g[2][mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n) {
		fori(i, 0, mxn)
			fori(j, 0, mxn)
				g[0][i][j] = g[1][i][j] = (i == j ? 0 : oo);
		fori(i, 0, n) {
			char a, b, u, v; cin >> a >> b >> u >> v;
			u = u - 'A';
			v = v - 'A';
			int w; cin >> w;
			g[(a == 'Y')][u][v] = min(g[(a == 'Y')][u][v], w);
			if (b == 'B') g[(a == 'Y')][v][u] = min(g[(a == 'Y')][u][v], w);
		}
		char s, t; cin >> s >> t;
		s = s - 'A';
		t = t - 'A';
		// Floyd Warshall
		fori(id, 0, 2)
			fori(k, 0, mxn)
				fori(i, 0, mxn)
					fori(j, 0, mxn)
						g[id][i][j] = min(g[id][i][j], g[id][i][k] + g[id][k][j]);
		int min_val = oo;
		fori(i, 0, mxn) if (g[1][s][i] != oo && g[0][t][i] != oo)
			min_val = min(min_val, g[1][s][i] + g[0][t][i]);
		if (min_val == oo) {
			cout << "You will never meet." << endl;
		} else {
			cout << min_val;
			fori(i, 0, mxn) if (g[1][s][i] != oo && g[0][t][i] != oo)
				if (g[1][s][i] + g[0][t][i] == min_val)
					cout << " " << (char)(i + 'A');
			cout << endl;
		}
	}
	return 0;
}
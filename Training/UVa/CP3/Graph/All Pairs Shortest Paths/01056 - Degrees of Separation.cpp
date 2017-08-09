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

int g[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, cs = 0;
	while (cin >> n >> m && n) {
		fori(i, 0, n) fori(j, 0, n) g[i][j] = (i == j ? 0 : oo);
		map<string, int> mapper;
		int id = 0;
		while (m--) {
			string a, b; cin >> a >> b;
			if (mapper[a] == 0) mapper[a] = ++id;
			if (mapper[b] == 0) mapper[b] = ++id;
			int u = mapper[a], v = mapper[b]; u--; v--;
			g[u][v] = g[v][u] = 1;
		}
		fori(k, 0, n)
			fori(i, 0, n)
				fori(j, 0, n)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int ans = 0;
		fori(i, 0, n)
			fori(j, 0, n)	
				ans = max(ans, g[i][j]);
		cout << "Network " << ++cs << ": ";
		if (ans == oo)
			cout << "DISCONNECTED" << endl;
		else
			cout << ans << endl;
		cout << endl;
	}
	return 0;
}
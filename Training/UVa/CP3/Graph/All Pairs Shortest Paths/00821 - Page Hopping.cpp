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

const int oo = 1e9, mxn = 100;

int g[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, y, cs = 0;
	while (cin >> x >> y && x) {
		fori(i, 0, 100)
			fori(j, 0, 100)
				g[i][j] = (i == j ? 0 : oo);
		g[x-1][y-1] = 1;
		while (cin >> x >> y && x)
			g[x-1][y-1] = 1;
		fori(k, 0, 100)
			fori(i, 0, 100)
				fori(j, 0, 100)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int acc = 0, n = 0;
		fori(i, 0, 100)
			fori(j, 0, 100)
				if (g[i][j] != oo && g[i][j] != 0)
					acc += g[i][j], n++;
		cout << "Case " << ++cs << ": average length between pages = " << fixed << setprecision(3) << (double)acc / n << " clicks" << endl;
	}
	return 0;
}
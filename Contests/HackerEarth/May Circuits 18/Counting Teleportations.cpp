#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 5010, MD = 1e9 + 7;

ll f[MN][MN], g[MN][MN], h[MN];

int main() {
	int n, m, k; cin >> n >> m >> k;
	vi v(m + 1, -1);
	v[0] = 1;
	int ok = 1;
	fori(i, 0, k) {
		int x, t; cin >> x >> t;
		if (v[t] != -1) ok = 0;
		v[t] = x;
	}
	ok &= (n > 1);
	if (!ok) { cout << 0 << endl; return 0; }
	f[1][0] = g[1][0] = 1;
	fori(j, 1, m + 1) {
		if (v[j - 1] == -1) {
			fori(i, 1, n + 1) {
				ll sum = (g[i - 1][j - 1] + g[i + 1][j - 1] + f[i][j - 1]) % MD;
				if (i > 1 && i < n) sum = (sum - g[i][j - 2] + MD) % MD;
				f[i][j] = (sum - h[i] + MD) % MD;
				g[i][j] = ((f[i][j] + h[i]) + f[i][j]) % MD;
				h[i] = (h[i] + f[i][j]) % MD;
			}
		} else {
			int x = v[j - 1];
			fori(i, 1, n + 1) if (i != x)
				h[i] = g[i][j - 1] = 0;
			if (x - 1 > 0) {
				f[x - 1][j] = f[x][j - 1];
				g[x - 1][j] = (f[x - 1][j] + f[x][j - 1]) % MD;
				h[x - 1] = f[x - 1][j];
			}
			g[x][j - 1] = g[x][j] = h[x] = f[x][j - 1];
			if (x < n) {
				f[x + 1][j] = f[x][j - 1];
				g[x + 1][j] = (f[x + 1][j] + f[x][j - 1]) % MD;
				h[x + 1] = f[x + 1][j];
			}
		}
	}
	cout << f[v[m]][m] << endl;
	return 0;
}

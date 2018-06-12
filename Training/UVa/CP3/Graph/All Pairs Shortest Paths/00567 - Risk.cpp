#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int g[20][20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n = 20;
	int k;
	for (int t = 0; cin >> k; t++) {
		fori(i, 0, n) fori(j, 0, n) g[i][j] = (i == j) ? 0 : oo;
		while(k--) {
			int x; cin >> x; x--;
			g[0][x] = 1;
			g[x][0] = 1;
		}
		fori(i, 1, n - 1) {
			cin >> k;
			while (k--) {
				int x; cin >> x; x--;
				g[i][x] = 1;
				g[x][i] = 1;
			}
		}
		fori(k, 0, n)
			fori(i, 0, n)
				fori(j, 0, n)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		cout << "Test Set #" << t + 1 << endl;
		int q; cin >> q;
		while (q--) {
			int a, b; cin >> a >> b;
			cout << setw(2) << a << " to " << setw(2) << b << ": " << g[a - 1][b - 1] << endl;
		}
		cout << endl;
	}
	return 0;
}

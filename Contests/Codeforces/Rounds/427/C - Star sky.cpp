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

int A[15][mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q, c; cin >> n >> q >> c;
	for (int i = 0; i < n; i++) {
		int x, y, s; cin >> x >> y >> s;
		for (int t = 0; t <= c; t++)
			A[t][x][y] += (s + t) % (c + 1);
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int t = 0; t <= c; t++) {
				A[t][i][j] += A[t][i-1][j];
				A[t][i][j] += A[t][i][j-1];
				A[t][i][j] -= A[t][i-1][j-1];
			}
		}
	}
	while (q--) {
		int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= (c + 1);
		int ans = A[t][x2][y2] - A[t][x1-1][y2] - A[t][x2][y1-1] + A[t][x1-1][y1-1];
		cout << ans << endl;
	}
	return 0;
}
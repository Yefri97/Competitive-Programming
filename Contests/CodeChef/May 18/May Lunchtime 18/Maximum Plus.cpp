#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MN = 1010;
const ll oo = 1e10;

int a[MN][MN];
int r1[MN][MN], r2[MN][MN];
int c1[MN][MN], c2[MN][MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> a[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 1, sum = a[i][0]; j < m; j++) {
				sum += a[i][j];
				r1[i][j] = sum;
				sum = max(a[i][j], sum);
			}
			for (int j = m - 2, sum = a[i][m - 1]; j >= 0; j--) {
				sum += a[i][j];
				r2[i][j] = sum;
				sum = max(a[i][j], sum);
			}
		}
		for (int j = 0; j < m; j++) {
			for (int i = 1, sum = a[0][j]; i < n; i++) {
				sum += a[i][j];
				c1[i][j] = sum;
				sum = max(a[i][j], sum);
			}
			for (int i = n - 2, sum = a[n - 1][j]; i >= 0; i--) {
				sum += a[i][j];
				c2[i][j] = sum;
				sum = max(a[i][j], sum);
			}
		}
		ll ans = -oo;
		fori(i, 1, n - 1)
			fori(j, 1, m - 1)
				ans = max(ans, 0LL + r1[i][j] + r2[i][j] + c1[i][j] + c2[i][j] - 3 * a[i][j]);
		cout << ans << endl;
	}
	return 0;
}

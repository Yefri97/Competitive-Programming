#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1e3 + 10;

int A[MX][MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> A[i][j];

	fori(i, 0, n)
		sort(A[i], A[i] + m);

	int ans = oo;

	fori(i, 0, n - 1) {
		fori(j, 0, m) {
			int x = A[i][j];
			int pos = lower_bound(A[i + 1], A[i + 1] + m, x) - A[i + 1];
			if (pos < m) ans = min(ans, abs(x - A[i + 1][pos]));
			if (pos > 0) ans = min(ans, abs(x - A[i + 1][pos - 1]));
		}
	}

	cout << ans << endl;

	return 0;
}
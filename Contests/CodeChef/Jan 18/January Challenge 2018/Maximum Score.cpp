#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MX = 1000;

int n;
int A[MX][MX];

ll solver() {
	fori(i, 0, n)
		sort(A[i], A[i] + n);
	ll x = A[n - 1][n - 1], ans = x;
	for (int i = n - 2; i >= 0; i--) {
		int pos = lower_bound(A[i], A[i] + n, x) - A[i];
		if (pos == 0) return -1;
		x = A[i][pos - 1];
		ans += x;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, n)
			fori(j, 0, n)
				cin >> A[i][j];
		ll ans = solver();
		cout << ans << endl;
	}
	return 0;
}
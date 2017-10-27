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

const int oo = 1e9, mxn = 510;

double dp[mxn][mxn];

double fexp(double b, int e) {
	if (e == 0) return 1.0;
	double ans = fexp(b, e / 2); ans *= ans;
	if (e % 2) ans *= b;
	return ans;
}

double prob(int n, int x, double p, double q) {
	if (n == 0) return 1.0;
	if (dp[n][x] != -1.0) return dp[n][x];
	double ans = 0;
	// LOSE
	ans += q * prob(n - 1, x, p, q);
	// WIN
	if (x >= n) {
		for (int i = 1; i < n; i++)
			ans += fexp(p, i) * q * prob(n - i - 1, x, p, q);
		ans += fexp(p, n);
	} else {
		for (int i = 1; i <= x; i++)
			ans += fexp(p, i) * q * prob(n - i - 1, x, p, q);
	}
	return dp[n][x] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	double p;
	while (cin >> n >> p && n) {
		fori(i, 0, mxn) fori(j, 0, mxn) dp[i][j] = -1.0;
		double ans = 0, q = 1.0 - p;
		for (int x = 1; x < n; x++) {
			double y = 0;
			y += fexp(p, x) * q * prob(n - x - 1, x, p, q);
			for (int i = 1; i < n - x; i++)
				y += prob(i - 1, x - 1, p, q) * q * fexp(p, x) * q * prob(n - (i + x) - 1, x, p, q);
			y += prob(n - x - 1, x - 1, p, q) * q * fexp(p, x);
			ans += x * y;
		}
		ans += n * fexp(p, n);
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
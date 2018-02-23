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

const int oo = 1e9, MX = 5000;

int dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		string a, b; cin >> a >> b;
		a.resize(distance(a.begin(), unique(a.begin(), a.end())));
		b.resize(distance(b.begin(), unique(b.begin(), b.end())));
		n = a.size();
		m = b.size();
		fori(i, 0, n)
			fori(j, 0, m)
				if (a[i] == b[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		cout << n + m - dp[n][m] << endl;
	}
	return 0;
}
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

int memo[mxn][mxn];
int A[mxn], B[mxn];

int solver(int n, int m) {
	if (n == -1 || m == -1) return 0;
	if (memo[n][m] != -1) return memo[n][m];
	if (A[n] == B[m]) return memo[n][m] = 1 + solver(n - 1, m - 1);
	return memo[n][m] = max(solver(n - 1, m), solver(n, m - 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, cs = 0;
	while (cin >> n >> m && n) {
		fori(i, 0, n)
			cin >> A[i];
		fori(i, 0, m)
			cin >> B[i];
		memset(memo, -1, sizeof memo);
		int ans = solver(n - 1, m - 1);
		cout << "Twin Towers #" << ++cs << endl;
		cout << "Number of Tiles : " << ans << endl;
		cout << endl;
	}
	return 0;
}
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

const int oo = 1e9, mxn = 110, kmod = 1e9 + 7;

int k, d;
int memo[mxn][2];

int solver(int n, int b) {
	if (n == 0) return b;
	if (memo[n][b] != -1) return memo[n][b];
	int ans = 0;
	for (int i = 1; i <= min(n, k); i++)
		ans = (ans + solver(n - i, (b ? b : (i >= d)))) % kmod;
	return memo[n][b] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n >> k >> d;
	memset(memo, -1, sizeof memo);
	int ans = solver(n, 0);
	cout << ans << endl;
	return 0;
}
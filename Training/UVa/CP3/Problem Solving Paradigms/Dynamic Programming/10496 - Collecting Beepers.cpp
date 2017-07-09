#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MAXN = 12;
int n, X[MAXN], Y[MAXN], dist[MAXN][MAXN], memo[MAXN][1 << MAXN];

int solver(int pos, int bitmask) {
	if (bitmask == (1 << (n + 1)) - 1) return dist[pos][0];
	if (memo[pos][bitmask] != -1) return memo[pos][bitmask];
	int ans = oo;
	fori(nxt, 0, n + 1)
		if (nxt != pos && !(bitmask & (1 << nxt)))
			ans = min(ans, solver(nxt, bitmask | (1 << nxt)) + dist[pos][nxt]);
	return memo[pos][bitmask] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int w, h; cin >> w >> h;
		cin >> X[0] >> Y[0];
		cin >> n;
		fori(i, 0, n)
			cin >> X[i + 1] >> Y[i + 1];
		fori(i, 0, n + 1)
			fori(j, 0, n + 1)
				dist[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
		memset(memo, -1, sizeof memo);
		int ans = solver(0, 1);
		cout << "The shortest path has length " << ans << endl;
	}
	return 0;
}
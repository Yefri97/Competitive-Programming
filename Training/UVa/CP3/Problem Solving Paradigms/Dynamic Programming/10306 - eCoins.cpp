// Coin Change (CC)
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define SQ(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 310;
int n, s;
ii A[MAXN];
int memo[MAXN][MAXN];

int solver(int a, int b) {
	if (SQ(a) + SQ(b) == SQ(s)) return 0;
	if (memo[a][b] != -1) return memo[a][b];
	int ans = INF;
	fori(i, 0, n)
		if (SQ(a + A[i].first) + SQ(b + A[i].second) <= SQ(s))
			ans = min(ans, solver(a + A[i].first, b + A[i].second) + 1);
	return memo[a][b] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		fori(i, 0, n)
			cin >> A[i].first >> A[i].second;
		memset(memo, -1, sizeof memo);
		int ans = solver(0, 0);
		if (ans == INF)
			cout << "not possible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
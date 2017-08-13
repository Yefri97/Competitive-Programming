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

const int oo = 1e9, mxn = 1010;

int n;
int P[mxn], W[mxn];
int memo[mxn][40];

int go(int id, int c) {
	if (id == n) return 0;
	if (memo[id][c] != -1) return memo[id][c];
	if (c < W[id]) return memo[id][c] = go(id + 1, c);
	return memo[id][c] = max(go(id + 1, c - W[id]) + P[id], go(id + 1, c));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, n)
			cin >> P[i] >> W[i];
		int ans = 0;
		memset(memo, -1, sizeof memo);
		int m; cin >> m;
		while (m--) {
			int c; cin >> c;
			ans += go(0, c);
		}
		cout << ans << endl;
	}
	return 0;
}
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

const int oo = 1e9, mxn = 100;

int memo[mxn];
vi g[mxn];

int countPaths(int u) {
	if (g[u].size() == 0) return 1;
	if (memo[u] != -1) return memo[u];
	int ans = 0;
	fori(i, 0, g[u].size())
		ans += countPaths(g[u][i]);
	return memo[u] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool first = true;
	int n;
	while (cin >> n) {
		if (!first) cout << endl; first = false;
		fori(i, 0, n + 1) g[i].clear();
		fori(i, 0, n) {
			int k; cin >> k;
			while (k--) {
				int x; cin >> x;
				g[i].push_back(x);
			}
		}
		memset(memo, -1, sizeof memo);
		int ans = countPaths(0);
		cout << ans << endl;
	}
	return 0;
}
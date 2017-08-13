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

const int oo = 1e9, mxn = 40;

int memo[mxn];
vi A[mxn], g[mxn];

void printPath(int u) {
	cout << u + 1 << " ";
	fori(i, 0, g[u].size()) {
		if (memo[u] == memo[g[u][i]] + 1) {
			printPath(g[u][i]);
			return;
		}
	}
}

int go(int u) {
	int ans = 0;
	if (memo[u] != -1) return memo[u];
	fori(i, 0, g[u].size())
		ans = max(ans, go(g[u][i]));
	return memo[u] = ans + 1;
}

bool isless(int i, int j) {
	fori(k, 0, A[i].size())
		if (A[i][k] >= A[j][k])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		fori(i, 0, n) { A[i].assign(m, 0); g[i].clear(); }
		fori(i, 0, n) {
			fori(j, 0, m)
				cin >> A[i][j];
			sort(A[i].begin(), A[i].end());
		}
		fori(i, 0, n)
			fori(j, 0, n) 
				if (isless(i, j))
					g[i].push_back(j);
		memset(memo, -1, sizeof memo);
		int ans = 0, start = -1;
		fori(i, 0, n) {
			int val = go(i);
			if (val > ans) {
				ans = val;
				start = i;
			}
		}
		cout << ans << endl;
		printPath(start);
		cout << endl;
	}
	return 0;
}
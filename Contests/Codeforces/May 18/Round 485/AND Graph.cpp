#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = (1 << 22) + 10;

int n;
int A[MN];
int vis[2][MN];

int comp(int x) { return ((1 << n) - 1) - x; }

void dfs(int u, int k) {
	if (k == 0) {
		vis[0][u] = 1;
		dfs(u, 1);
	} else {
		vis[1][u] = 1;
		fori(i, 0, n) if (((u >> i) & 1) == 0) {
			int v = u | (1 << i);
			if (!vis[1][v])
				dfs(v, 1);
		}
		int c = comp(u);
		if (A[c] && !vis[0][c])
			dfs(c, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m; cin >> n >> m;
	fori(i, 0, m) {
		int x; cin >> x;
		A[x] = 1;
	}
	int ans = 0;
	fori(i, 0, (1 << n)) if (A[i] && !vis[0][i]) {
		dfs(i, 0);
		ans++;
	}
	cout << ans << endl;
	return 0;
}

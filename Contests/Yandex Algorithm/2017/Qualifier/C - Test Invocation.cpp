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

const int oo = 1e9, mxn = 60;

vi g[mxn], deep;

void dfs(int u, int d) {
	deep[u] = d;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (deep[v] == -1)
			dfs(v, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<ll> v(n);
	fori(i, 0, n)
		cin >> v[i];
	fori(u, 0, n) {
		int k; cin >> k;
		while (k--) {
			int v; cin >> v; v--;
			g[u].push_back(v);
		}
	}
	deep.assign(n, -1);
	dfs(0, 0);
	ll acc = 0, ans = 0;
	fori(i, 0, n) {
		acc += v[i];
		ans += (1LL << deep[i]) * v[i];
	}
	cout << acc << " " << ans << endl;
	return 0;
}
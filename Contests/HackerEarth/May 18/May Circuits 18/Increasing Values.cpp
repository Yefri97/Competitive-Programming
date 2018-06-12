#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ll> vll;

const int oo = 1e9, MN = 100010, ML = 18;

int curr;
int in[MN], out[MN];
int par[MN][ML]; // initialize -1
int good[MN];
vi g[MN];

struct FenwickTree {
	int n;
	vll data;
	FenwickTree(int _n) : n(_n), data(vll(n)) {}
	void update(int at, ll by) {
		while (at < n) data[at] += by, at |= at + 1;
	}
	ll query(int at) {
		ll res = 0;
		while (at >= 0) res += data[at], at = (at & (at + 1)) - 1;
		return res;
	}
	ll rsq(int a, int b) { return query(b) - query(a - 1); }
};

void dfs(int u, int p) {
	par[u][0] = p;
	in[u] = ++curr;
	for (int i = 1; i < ML; i++)
		if (par[u][i - 1] != -1)
			par[u][i] = par[par[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
		dfs(v, u);
	out[u] = curr;
}

ll sum(FenwickTree &ft, int u) {
	return ft.rsq(in[u], out[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q, x; cin >> n >> q >> x;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	curr = -1;
	memset(par, -1, sizeof par);
	dfs(0, -1);
	FenwickTree ft(n);
	fori(i, 0, n) {
		ll val; cin >> val;
		ft.update(in[i], val);
	}
	int cnt = 0;
	fori(i, 0, n) {
		if (sum(ft, i) > x) {
			cnt++;
			good[i] = 1;
		}
	}
	while (q--) {
		int d, a; cin >> d >> a; d--;
		ft.update(in[d], a);
		if (good[d] == 0 && sum(ft, d) <= x) {
			for (int i = ML - 1; i >= 0; i--) {
				int p = par[d][i];
				if (p != -1 && sum(ft, p) <= x)
					d = p;
			}
			d = par[d][0];
		}
		while (d != -1 && good[d] == 0) {
			good[d] = 1;
			cnt++;
			d = par[d][0];
		}
		cout << cnt << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010, ML = 18;

vi g[MN];
set<ii> edges;
int cnt, h[MN];
int in[MN], out[MN], d[MN];
int par[MN][ML];

struct SegmentTree {

	int n;
	vi A;
	vi tree;
	vi lazy;

	SegmentTree(vi &_A) {
		A = _A;
		n = _A.size();
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	void build(int p, int i, int j) {
		if (i == j) {
			tree[p] = A[i];
		} else {
			int mid = (i + j) / 2;
			build(2 * p, i, mid);
			build(2 * p + 1, mid + 1, j);
		}
	}

	int query(int p, int i, int j, int L, int R) {
		if (j < L || R < i) return 0;
		if (lazy[p] != 0) {
			if (i == j) {
				tree[p] ^= lazy[p];
			} else {
				lazy[2 * p] ^= lazy[p];
				lazy[2 * p + 1] ^= lazy[p];
			}
			lazy[p] = 0;
		}
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		int q1 = query(2 * p, i, mid, L, R);
		int q2 = query(2 * p + 1, mid + 1, j, L, R);
		return q1 ^ q2;
	}

	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}

	void update(int p, int i, int j, int L, int R, int new_value) {
		if (lazy[p] != 0) {
			if (i == j) {
				tree[p] ^= lazy[p];
			} else {
				lazy[2 * p] ^= lazy[p];
				lazy[2 * p + 1] ^= lazy[p];
			}
			lazy[p] = 0;
		}
		if (j < L || R < i) return;
		if (L <= i && j <= R) {
			if (i == j) {
				tree[p] ^= new_value;
			} else {
				lazy[2 * p] ^= new_value;
				lazy[2 * p + 1] ^= new_value;
			}
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, L, R, new_value);
		update(2 * p + 1, mid + 1, j, L, R, new_value);
	}

	void update(int i, int j, int new_value) {
		update(1, 0, n - 1, i, j, new_value);
	}

};

void dfs(int u, int p) {
	par[u][0] = p;
	if (p != -1)
		d[u] = d[p] + 1;
	in[u] = ++cnt;
	for (int i = 1; i < ML; i++)
		if (par[u][i - 1] != -1)
			par[u][i] = par[par[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != p)
		dfs(v, u);
	out[u] = cnt;
}

int lca(int u, int v) {
	if (d[u] < d[v])
		swap(u, v);
	for (int i = ML - 1; i >= 0; i--)
		if (par[u][i] != -1 && d[par[u][i]] >= d[v])
			u = par[u][i];
	// d[u] = d[v]
	if (u == v) return u;
	for (int i = ML - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int dist(int u, int v) {
	return d[u] + d[v] - 2 * d[lca(u, v)];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand (time(NULL));
	int n; cin >> n;
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.insert(ii(u, v));
		edges.insert(ii(v, u));
	}
	cnt = -1;
	memset(par, -1, sizeof par);
	memset(h, -1, sizeof h);
	dfs(0, -1);
	vi group(n);
	SegmentTree st(group);
	int q; cin >> q;
	while (q--) {
		char c; cin >> c;
		int u, v; cin >> u >> v; u--; v--;
		if (c == 'd' || c == 'c') {
			if (edges.find(ii(u, v)) == edges.end()) continue;
			int x = (d[u] > d[v] ? u : v);
			if (c == 'd') {
				if (h[x] != -1) continue;
				h[x] = rand() % oo;
				st.update(in[x], out[x], h[x]);
			} else {
				if (h[x] == -1) continue;
				st.update(in[x], out[x], h[x]);
				h[x] = -1;
			}
		} else {
			int c1 = st.query(in[u], in[u]);
			int c2 = st.query(in[v], in[v]);
			if (c1 != c2) {
				cout << "Impossible" << endl;
			} else {
				cout << dist(u, v) << endl;
			}
		}
	}
	return 0;
}

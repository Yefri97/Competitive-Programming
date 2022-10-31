int depth[Mxn], sp[Mxn][Lg];
int heavy[Mxn], rep[Mxn], par[Mxn], dp[Mxn], pos[Mxn], wh[Mxn], t;
int st[Mxn*4];
vi g[Mxn];

void bld(int p, int l, int r) {
	if(l == r) st[p] = pos[l];
	else {
		int mid = (l + r) >> 1, left = p << 1, right = left+1;
		bld(left, l, mid);
		bld(right, mid+1, r);
		st[p] = max(st[left], st[right]);
	}
}

void upd(int p, int l, int r, int idx, int val) {
	if(idx < l || r < idx) return;
	if(l == r) st[p] = val;
	else {
		int mid = (l + r) >> 1, left = p << 1, right = left+1;
		upd(left, l, mid, idx, val);
		upd(right, mid+1, r, idx, val);        
		st[p] = max(st[left], st[right]);
	}
}

int qry(int p, int l, int r, int ql, int qr) {
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return st[p];
	int mid = (l + r) >> 1, left = p << 1, right = left+1;
	return max(qry(left, l, mid, ql, qr), qry(right, mid+1, r, ql, qr));     
}

void dfs(int u) {
	dp[u] = 1;
	int mx = 0;
	for(auto & v : g[u]) {
		if(v == par[u]) continue;
		par[v] = u;
		depth[v] = depth[u] + 1;
		sp[v][0] = u;
		fori(i,1,Lg) sp[v][i] = sp[sp[v][i-1]][i-1];
		dfs(v);
		dp[u] += dp[v];
		if(dp[v] > mx) {
			mx = dp[v];
			heavy[u] = v;
		}
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	forr(i,Lg-1,0) {
		if(depth[u] - (1 << i) >= depth[v]) u = sp[u][i];
	}
	if(u == v) return u;
	forr(i,Lg-1,0) {
		if(sp[u][i] != sp[v][i]) {
			u = sp[u][i];
			v = sp[v][i];
		}
	}
	return sp[u][0];
}

void build(int u, int head) {
	rep[u] = head, pos[t] = a[u], wh[u] = t;
	t++;
	if(heavy[u] != -1) build(heavy[u], head);
	for(auto & v : g[u]) {
		if(v != par[u] && v != heavy[u]) build(v, v);
	}
}

int qry_hld(int u, int v) {
	int ans = 0;
	for(; rep[u] != rep[v]; u = par[rep[u]]) {
		ans = max(ans, qry(1, 0, t, wh[rep[u]], wh[u]));
	}
	ans = max(ans, qry(1, 0, t, wh[v], wh[u]));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	fori(i,0,n) cin >> a[i];
	fori(i,1,n) {
		int u, v; cin >> u >> v;
		u--, v--;
		g[u].eb(v);
		g[v].eb(u);
	}
	memset(heavy, -1, sizeof heavy);
	dfs(0);
	build(0, 0);
	bld(1, 0, t);
	fori(i,0,q) {
		int c;
		cin >> c;
		if(c == 1) {
			int u, x;
			cin >> u >> x;
			u--;
			upd(1, 0, t, wh[u], x);
		} else {
			int u, v;
			cin >> u >> v;
			u--, v--;
			int lc = lca(u, v);
			cout << max(qry_hld(u, lc), qry_hld(v, lc)) << ' ';
		}
	}
	return 0; 
}
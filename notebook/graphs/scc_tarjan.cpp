int cnt, nComps, compOf[MN];
int low[MN], num[MN], vis[MN];
vi g[MN];
stack<int> st;

void scc(int u) {
	low[u] = num[u] = cnt++;
	st.push(u);
	vis[u] = 1;
	for (int v : g[u]) {
		if (num[v] == -1)
			scc(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u]) {
		while (true) {
			int v = st.top(); st.pop();
			vis[v] = 0;
			compOf[v] = nComps;
			if (u == v) break;
		}
		nComps++;
	}
}

int main() {
	memset(num, -1, sizeof num);
	fori(i, 0, n) if (num[i] == -1)
		scc(i);
}
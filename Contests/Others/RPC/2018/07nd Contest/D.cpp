#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 500;

int b, r;
int match[MN], vis[MN];
vi g[MN];
ii points[MN];

double dist(int i, int j) {
	int dx = points[i].x - points[j + b].x;
	int dy = points[i].y - points[j + b].y;
	return sqrt(dx * dx + dy * dy);
}

int dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (int v : g[u]) {
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int can(double d, int k) {
	fori(i, 0, b + r) g[i].clear();
	fori(i, 0, b) fori(j, 0, r) if (dist(i, j) < d) {
		g[i].push_back(j + b);
		g[j + b].push_back(i);
	}
	int mcbm = 0;
	memset(match, -1, sizeof match);
	fori(u, 0, b) {
		memset(vis, 0, sizeof vis);
		mcbm += dfs(u);
	}
	return k >= mcbm;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n >> b >> r;
	fori(i, 0, b + r)
		cin >> points[i].x >> points[i].y;
	double lo = 0.0, hi = oo;
	fori(i, 0, 60) {
		double mi = (lo + hi) * 0.5;
		if (can(mi, r + b - n))
			lo = mi;
		else
			hi = mi;
	}
	cout << fixed << setprecision(8) << lo << endl;
	return 0;
}

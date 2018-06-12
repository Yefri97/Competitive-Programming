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

const int oo = 1e9;

struct edge {
	int u, v, w;
	edge() {}
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const edge &o) const { return w < o.w; }
};

int p[110];

int findSet(int i) { return (p[i] == i ? i : (p[i] = findSet(p[i]))); }
void unionSet(int i, int j) { p[findSet(j)] = findSet(i); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<edge> edges(m);
		fori(i, 0, m)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		// Kruskal Algorithm
		sort(edges.rbegin(), edges.rend());
		fori(i, 0, n) p[i] = i;
		int ans;
		fori(i, 0, m) {
			edge e = edges[i];
			if (findSet(e.u) != findSet(e.v)) {
				unionSet(e.u, e.v);
				ans = e.w;
			}
		}
		cout << "Case #" << ++cs << ": " << ans << endl;
	}
	return 0;
}
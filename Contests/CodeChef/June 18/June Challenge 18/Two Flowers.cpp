#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> Edge;

const int oo = 1e9, MN = 2010;

int n, m;
int p[MN * MN], grid[2][MN][MN], sz[2][MN * MN];
ii curr[MN * MN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int idx, int color) {
	sz[0][idx]++;
	grid[1][x][y] = idx;
	fori(k, 0, 4) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[0][nx][ny] != color) continue;
		if (grid[1][nx][ny] == 0)
			dfs(nx, ny, idx, color);
	}
}

int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }

void unnionSet(int i, int j) {
	int a = findSet(j), b = findSet(i);
	if (a != b) { p[a] = b; sz[1][b] += sz[1][a]; curr[b] = curr[a]; }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> grid[0][i][j];
	int n2 = 1;
	fori(i, 0, n) fori(j, 0, m) {
		if (grid[1][i][j] == 0) {
			dfs(i, j, n2, grid[0][i][j]);
			n2++;
		}
	}
	vector<Edge> edges;
	fori(i, 0, n) fori(j, 0, m) {
		fori(k, 0, 2) {
			int ni = i + dx[k], nj = j + dy[k];
			if (ni < n && nj < m && grid[0][i][j] != grid[0][ni][nj]) {
				int u = grid[0][i][j], v = grid[0][ni][nj];
				int a = grid[1][i][j], b = grid[1][ni][nj];
				if (u > v) swap(u, v), swap(a, b);
				edges.push_back(Edge(u, v, a, b));
			}
		}
	}
	sort(edges.begin(), edges.end());
	memset(p, -1, sizeof p);
	int ans = *max_element(sz[0], sz[0] + n2);
	for (auto e : edges) {
		int u, v, a, b;
		tie(u, v, a, b) = e;
		int s1 = findSet(a), s2 = findSet(b);
		if (curr[s1] != ii(u, v)) p[a] = -1, sz[1][a] = sz[0][a], curr[a] = ii(u, v);
		if (curr[s2] != ii(u, v)) p[b] = -1, sz[1][b] = sz[0][b], curr[b] = ii(u, v);
		unnionSet(a, b);
		ans = max(ans, sz[1][findSet(a)]);
	}
	cout << ans << endl;
	return 0;
}

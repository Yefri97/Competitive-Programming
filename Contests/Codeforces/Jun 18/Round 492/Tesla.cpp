#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int oo = 1e9;

int grid[4][50];

void show(vector<iii> &v) {
	cout << v.size() << endl;
	for (auto c : v) {
		int id, x, y;
		tie(id, x, y) = c;
		cout << id << " " << x << " " << y << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	int m = 2 * n;
	fori(i, 0, 4)
		fori(j, 0, n)
			cin >> grid[i][j];
	reverse(grid[2], grid[2] + n);
	reverse(grid[3], grid[3] + n);
	vector<iii> ans;
	fori(i, 0, n) if (grid[1][i] && grid[1][i] == grid[0][i]) {
		ans.emplace_back(grid[1][i], 1, i + 1);
		grid[1][i] = 0;
	}
	fori(i, 0, n) if (grid[2][i] && grid[2][i] == grid[3][i]) {
		ans.emplace_back(grid[2][i], 4, n - i);
		grid[2][i] = 0;
	}
	if (ans.size() == k) { show(ans); return 0; }
	int s = -1;
	fori(i, 0, 2 * n) if (grid[i / n + 1][i % n]) {
		int j = (i + 1) % m;
		if (grid[j / n + 1][j % n] == 0)
			s = i;
	}
	if (s == -1) { cout << -1 << endl; return 0; }
	vi pos(k + 1);
	queue<int> q;
	fori(i, 0, 2 * n) {
		int u = (s - i + m) % m;
		int id = grid[u / n + 1][u % n];
		if (id > 0) {
			pos[id] = u;
			q.push(id);
		}
	}
	while (!q.empty()) {
		int id = q.front(); q.pop();
		int u = pos[id], v = (u + 1) % m;
		ans.emplace_back(id, v / n + 2, (v < n ? v % n + 1 : n - v % n));
		int x = v / n + 1 + (v < n ? -1 : 1), y = v % n;
		if (grid[x][y] == id) {
			ans.emplace_back(id, x + 1, (v < n ? y + 1 : n - y));
		} else {
			pos[id] = v;
			q.push(id);
		}
	}
	show(ans);
	return 0;
}

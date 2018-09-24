#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 30;

int grid[MN][MN];
vi a[MN], b[MN];

void delet(multiset<int> &dict, int x) {
	auto it = dict.find(x);
	dict.erase(it);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> grid[i][j];
	int len1 = (n + m - 3) / 2, len2 = (n + m - 2) / 2;
	fori(mask, 0, 1 << len1) {
		int x = 0, y = 0, xr = grid[x][y];
		fori(bit, 0, len1) {
			if ((mask >> bit) & 1) x++;
			else y++;
			if (x < n && y < m)
				xr ^= grid[x][y];
		}
		if (x < n && y < n)
			a[y].push_back(xr);
	}
	fori(mask, 0, 1 << len2) {
		int x = n - 1, y = m - 1, xr = k ^ grid[x][y];
		fori(bit, 0, len2) {
			if ((mask >> bit) & 1) x--;
			else y--;
			if (x >= 0 && y >= 0)
				xr ^= grid[x][y];
		}
		if (x >= 0 && y >= 0)
			b[y].push_back(xr);
	}
	multiset<int> dict;
	for (int x : b[0])
		dict.insert(x);
	int ans = 0;
	fori(i, 0, m) {
		for (int x : b[i + 1])
			dict.insert(x);
		for (int x : a[i])
			ans += dict.count(x);
		for (int x : b[i])
			delet(dict, x);
	}
	cout << ans << endl;
	return 0;
}

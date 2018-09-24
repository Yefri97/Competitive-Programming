#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 2010;

int idx, a[MN], b[MN];
int l[MN], r[MN];
int label[MN], pos[MN];

void dfs(int t, int u) {
	if (u == 0) return;
	if (t == 0)
		a[idx++] = u;
	dfs(t, l[u]);
	dfs(t, r[u]);
	if (t == 1)
		b[idx++] = u;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	fori(t, 0, tc) {
		int n, k; cin >> n >> k;
		fori(i, 1, n + 1)
			cin >> l[i] >> r[i];
		idx = 0;
		dfs(0, 1);
		idx = 0;
		dfs(1, 1);
		memset(label, -1, sizeof label);
		fori(i, 0, n)
			pos[a[i]] = i;
		int c = 0;
		fori(i, 0, n) if (label[a[i]] == -1) {
			c = min(k, c + 1);
			label[a[i]] = c;
			int u = b[i];
			while (u != a[i]) {
				label[u] = c;
				u = b[pos[u]];
			}
		}
		cout << "Case #" << t + 1 << ":";
		if (c < k) {
			cout << " Impossible" << endl;
		} else {
			fori(i, 1, n + 1)
				cout << " " << label[i];
			cout << endl;
		}
	}
	return 0;
}

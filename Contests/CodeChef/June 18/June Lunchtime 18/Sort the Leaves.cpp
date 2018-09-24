#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

int l[MN], r[MN];
int mn[MN], mx[MN];

ll dfs(int u) {
	if (l[u] == -1) {
		mn[u] = r[u];
		mx[u] = r[u];
		return 0;
	}
	int v1 = l[u] - 1, v2 = r[u] - 1;
	ll ans = 0;
	ans += dfs(v1);
	ans += dfs(v2);
	if (mx[v1] + 1 != mn[v2] && mx[v2] + 1 != mn[v1]) return oo;
	if (mx[v2] + 1 == mn[v1]) {
		mn[u] = mn[v2];
		mx[u] = mx[v1];
		ans++;
	} else {
		mn[u] = mn[v1];
		mx[u] = mx[v2];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n)
			cin >> l[i] >> r[i];
		ll ans = dfs(0);
		cout << (ans < oo ? ans : -1) << endl;
	}
	return 0;
}

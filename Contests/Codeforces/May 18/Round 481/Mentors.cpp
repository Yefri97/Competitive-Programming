#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int calc(vi &v, int x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector< vi > g(n);
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	while (m--) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(v[b]);
		g[b].push_back(v[a]);
	}
	vi t = v;
	sort(v.begin(), v.end());
	fori(i, 0, n)
		sort(g[i].begin(), g[i].end());
	fori(i, 0, n) {
		int cnt = 0;
		cnt += calc(v, t[i]);
		cnt -= calc(g[i], t[i]);
		cout << cnt << " ";
	}
	cout << endl;
	return 0;
}

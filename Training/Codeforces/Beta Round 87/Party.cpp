#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 2010;

vi g[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 1, n + 1) {
		int p; cin >> p;
		if (p != -1)
			g[p].push_back(i);
		else
			g[0].push_back(i);
	}
	int ans = 0;
	queue<ii> q; q.push(ii(0, 0));
	while (!q.empty()) {
		ii f = q.front(); q.pop();
		int u = f.first, d = f.second;
		ans = max(ans, d);
		for (int v : g[u])
			q.push(ii(v, d + 1));
	}
	cout << ans << endl;
	return 0;
}

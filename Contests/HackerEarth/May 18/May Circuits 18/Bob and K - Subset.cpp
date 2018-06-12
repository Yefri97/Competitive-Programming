#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = (1 << 11);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	n = v.size();
	queue<ii> q;
	vi seen(MX);
	fori(i, 0, n) {
		q.push(ii(v[i], 1));
		seen[v[i]] = 1;
	}
	int ans = 0;
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		int x = u.first;
		int y = u.second;
		ans++;
		fori(i, 0, n) {
			int nx = x | v[i], ny = y + 1;
			if (ny > k || seen[nx]) continue;
			seen[nx] = 1;
			q.push(ii(nx, ny));
		}
	}
	cout << ans << endl;
	return 0;
}

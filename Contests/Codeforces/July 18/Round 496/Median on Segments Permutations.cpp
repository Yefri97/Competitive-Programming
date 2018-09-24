#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vi v(n);
	int p = -1;
	fori(i, 0, n) {
		int x; cin >> x;
		v[i] = x;
		if (x == m) p = i;
	}
	map<int, int> cnt;
	for (int i = p, a = 0, b = 0; i < n; i++) {
		a += (v[i] < m);
		b += (v[i] > m);
		cnt[b - a]++;
	}
	ll ans = 0;
	for (int i = p, a = 0, b = 0; i >= 0; i--) {
		a += (v[i] < m);
		b += (v[i] > m);
		ans += cnt[a - b];
		ans += cnt[a - b + 1];
	}
	cout << ans << endl;
	return 0;
}

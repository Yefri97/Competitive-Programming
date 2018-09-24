#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int solve(int n, int m, ll sum, vi &d) {
	if (sum <= m) return 0;
	fori(k, 0, n) {
		sum -= d[k];
		if (sum <= m)
			return k + 1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	ll sum = 0;
	vi d(n);
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		sum += a;
		d[i] = a - b;
	}
	sort(d.rbegin(), d.rend());
	int ans = solve(n, m, sum, d);
	cout << ans << endl;
	return 0;
}

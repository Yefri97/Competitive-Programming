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
	int n, k, l; cin >> n >> k >> l;
	int m = n * k;
	vi v(m);
	fori(i, 0, m)
		cin >> v[i];
	sort(v.begin(), v.end());
	int p = upper_bound(v.begin(), v.end(), v[0] + l) - v.begin();
	if (n > p) { cout << 0 << endl; return 0; }
	ll ans = 0, c = n;
	for (int i = 0; i * k < p; i++) {
		ans += v[i * k];
		c--;
	}
	for (int i = p - 1; c > 0; i--) {
		if (i % k == 0) continue;
		ans += v[i];
		c--;
	}
	cout << ans << endl;
	return 0;
}

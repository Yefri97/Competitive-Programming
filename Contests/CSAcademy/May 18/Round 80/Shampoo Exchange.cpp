#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool can(vi &v, int c, int k, ll x, ll s) {
	ll ans = 0;
	fori(i, 0, k)
		ans += min((ll)(c - v[i]), x);
	return ans >= s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, c; cin >> n >> c;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	ll acc = accumulate(v.begin(), v.end(), 0LL);
	int k = (acc + c - 1) / c;
	if (k == n) {
		cout << k << " " << 0 << endl;
		return 0;
	}
	ll sum = accumulate(v.begin() + k, v.end(), 0LL);
	if (can(v, c, k, v[k], sum)) {
		cout << k << " " << v[k] << endl;
		return 0;
	}
	ll lo = v[k], hi = sum;
	while (hi - lo > 1) {
		ll mi = (lo + hi) >> 1;
		if (can(v, c, k, mi, sum))
			hi = mi;
		else
			lo = mi;
	}
	cout << k << " " << hi << endl;
	return 0;
}

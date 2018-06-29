#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 200010, MD = 1e9 + 7;

ll f[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	f[1] = 1;
	fori(i, 2, MN)
		f[i] = ((2LL * i - 1) * f[i - 1]) % MD;
	int n; cin >> n;
	vector<ll> a(2 * n);
	fori(i, 0, 2 * n)
		cin >> a[i];
	ll ans = (f[n] * (a[2 * n - 1] - a[0])) % MD;
	fori(i, 1, n) {
		ll c = (f[i] * f[n - i]) % MD;
		ans = (ans - ((a[2 * i] - a[2 * i - 1]) * c) % MD + MD) % MD;
	}
	cout << ans << endl;
	return 0;
}

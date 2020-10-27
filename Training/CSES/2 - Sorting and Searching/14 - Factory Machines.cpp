#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll oo = 1e18;

int can(ll x, ll t, vi &a) {
	fori(i, 0, SZ(a)) {
		t -= x / a[i];
		if (t <= 0) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, t; cin >> n >> t;
	vi a(n);
	for (int &x : a) cin >> x;
	ll lo = 0, hi = oo;
	while (hi - lo > 1) {
		ll mi = (lo + hi) / 2;
		if (can(mi, t, a)) hi = mi;
		else lo = mi;
	}
	cout << hi << endl;
	return 0;
}

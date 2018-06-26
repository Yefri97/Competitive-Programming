#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MD = 1e9 + 7;

ll fastExp(ll b, ll e) {
	ll ans = 1;
	while (e) {
		if (e & 1)
			ans = (ans * b) % MD;
		b = (b * b) % MD;
		e >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll x, k; cin >> x >> k;
	if (x == 0) { cout << 0 << endl; return 0; }
	x %= MD;
	ll pw = fastExp(2, k);
	ll a = (x * pw) % MD;
	ll b = (a - (pw - 1) + MD) % MD;
	ll c = (((a * (a + 1)) % MD) - ((b * (b - 1)) % MD) + MD) % MD;
	ll ans = (c * fastExp(pw, MD - 2)) % MD;
	cout << ans << endl;
	return 0;
}

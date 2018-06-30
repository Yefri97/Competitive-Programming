#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int can(ll n, ll k) {
	ll sum = 0, x = n;
	while (x > 0) {
		ll c = min(k, x);
		sum += c;
		x -= c;
		x -= x / 10;
	}
	return 2 * sum >= n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	ll lo = 0, hi = n;
	while (hi - lo > 1) {
		ll mi = (hi + lo) / 2;
		if (can(n, mi))
			hi = mi;
		else
			lo = mi;
	}
	cout << hi << endl;
	return 0;
}

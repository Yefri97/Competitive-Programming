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
	int n; cin >> n;
	while (n--) {
		ll p, q, b; cin >> p >> q >> b;
		ll g = __gcd(p, q);
		p /= g; q /= g;
		while (true) {
			ll x = __gcd(b, q);
			if (x == 1) break;
			while (q % x == 0) q /= x;
		}
		cout << (q == 1 ? "Finite" : "Infinite") << endl;
	}
	return 0;
}

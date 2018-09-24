#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

ll f(ll a, ll b, ll x) { return x * (a - x) * (b - x); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int lo = 0, hi = min(a, b);
		while (hi - lo > 1) {
			int mi = (hi + lo) / 2;
			if (f(a, b, mi) < f(a, b, mi + 1))
				lo = mi;
			else
				hi = mi;
		}
		cout << lo + 1 << " " << f(a, b, lo + 1) << endl;
	}
	return 0;
}

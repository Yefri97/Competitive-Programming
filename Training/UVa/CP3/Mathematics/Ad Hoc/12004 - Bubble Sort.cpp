#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll p = n * (n - 1), q = 4;
		ll gcd = __gcd(p, q);
		p /= gcd;
		q /= gcd;
		cout << "Case " << ++cs << ": " << p;
		if (q != 1) cout << "/" << q;
		cout << endl;
	}
	return 0;
}
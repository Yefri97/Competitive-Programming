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
	ll n;
	while (cin >> n && n) {
		vector<ll> v;
		for (ll i = 1; i * i <= n; i++) if (n % i == 0) {
			v.push_back(i);
			if (i * i != n) v.push_back(n / i);
		}
		int m = v.size(), ans = 0;
		fori(i, 0, m)
			fori(j, 0, i)
				ans += ((v[i] * v[j]) / __gcd(v[i], v[j])) == n;
		cout << n << " " << ans + 1 << endl;
	}
	return 0;
}
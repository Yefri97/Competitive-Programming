#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

ll lcm(ll a, ll b, ll c) { 
	ll d = (a * b) / __gcd(a, b);
	return (d * c) / __gcd(d, c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	if (n == 1 || n == 2) {
		cout << n << endl;
	} else {
		if (n % 2 == 0) {
			cout << max(lcm(n - 3, n - 1, n), lcm(n - 3, n - 2, n - 1)) << endl;
		} else {
			cout << lcm(n - 2, n - 1, n) << endl;
		}
	}
	return 0;
}
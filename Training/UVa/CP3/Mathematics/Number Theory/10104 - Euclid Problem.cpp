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
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;

const int oo = 1e9;

ll x, y, d;

void extendedEuclidean(ll a, ll b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extendedEuclidean(b, a % b);
	ll x1 = x;
	ll y1 = y;
	x = y1;
	y = x1 - y1 * (a / b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b;
	while (cin >> a >> b) {
		extendedEuclidean(a, b);
		cout << x << " " << y << " " << d << endl;
	}
	return 0;
}
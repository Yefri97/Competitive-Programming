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
	map<ll, int> mapper;
	map<ii, int> points;
	ll n, a, b; cin >> n >> a >> b;
	ll ans = 0;
	fori(i, 0, n) {
		ll x, vx, vy; cin >> x >> vx >> vy;
		ll d = vy - a * vx;
		ans += mapper[d];
		mapper[d]++;
		ii c = ii(vx, vy);
		ans -= points[c];
		points[c]++;
	}
	ans *= 2LL;
	cout << ans << endl;
	return 0;
}

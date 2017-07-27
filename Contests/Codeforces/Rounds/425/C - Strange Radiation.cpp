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

const ll oo = 1e7, mxn = 1e6;
const double eps = 1e-6;

ll s;
int preSumLeft[mxn + 10], preSumRight[mxn + 10];
vii pleft, pright;

bool check(double t) {
	bool flagLeft = false, flagRight = false;
	// Left
	memset(preSumLeft, 0, sizeof preSumLeft);
	fori(i, 0, pleft.size()) {
		ll p = pleft[i].first, v = pleft[i].second;
		if (p <= v * t) flagLeft = true;
		ll x = min(mxn, (ll)((t * (sq(s) - sq(v)) + p * v) / s));
		if (x < p) continue;
		preSumLeft[p]++;
		if (x != mxn) preSumLeft[x + 1]--;
	}
	// Right
	memset(preSumRight, 0, sizeof preSumRight);
	fori(i, 0, pright.size()) {
		ll p = mxn - pright[i].first, v = pright[i].second;
		if (p <= v * t) flagRight = true;
		ll x = min(mxn, (ll)((t * (sq(s) - sq(v)) + p * v) / s));
		if (x < p) continue;
		preSumRight[mxn - p]++;
		if (x != mxn) preSumRight[mxn - x - 1]--;
	}
	// PreSum
	int a = 0, b = 0;
	fori(i, 0, mxn + 1) {
		a += preSumLeft[i];
		preSumLeft[i] = (a > 0);
		//
		b += preSumRight[mxn - i];
		preSumRight[mxn - i] = (b > 0);
	}
	// Test
	fori(i, 0, mxn + 1)
		if ((flagLeft || preSumLeft[i]) && (flagRight || preSumRight[i]))
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n >> s;
	fori(i, 0, n) {
		int p, v, dir; cin >> p >> v >> dir;
		if (dir == 1) pleft.push_back(ii(p, v));
		if (dir == 2) pright.push_back(ii(p, v));
	}
	double low = 0.0, high = oo;
	while (high - low > eps) {
		double mid = (high + low) * 0.5;
		if (check(mid)) high = mid;
		else low = mid;
	}
	cout << fixed << setprecision(6) << high << endl;
	return 0;
}
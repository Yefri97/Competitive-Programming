#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9 + 10;

int can(double f, int m, int n, vi &a, vi &b) {
	fori(i, 0, n) {
		double x = (m + f) * 1.0 / a[i];
		if (x > f) return 0;
		f -= x;
		double y = (m + f) * 1.0 / b[(i + 1) % n];
		if (y > f) return 0;
		f -= y;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vi a(n), b(n);
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 0, n)
		cin >> b[i];
	double lo = 0.0, hi = oo;
	if (!can(hi, m, n, a, b)) { cout << -1 << endl; return 0; }
	fori(i, 0, 100) {
		double mi = (lo + hi) * 0.5;
		if (can(mi, m, n, a, b))
			hi = mi;
		else
			lo = mi;
	}
	cout << fixed << setprecision(10) << hi << endl;
	return 0;
}
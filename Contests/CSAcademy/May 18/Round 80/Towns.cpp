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
	int n, x; cin >> n >> x;
	vi d(n), s(n);
	fori(i, 0, n)
		cin >> d[i];
	fori(i, 0, n)
		cin >> s[i];
	double ans = -1.0;
	double lo = 0.0, hi = 1e5;
	fori(j, 0, 100) {
		double mi = (lo + hi) * 0.5;
		double sum = 0;
		int total = 0;
		fori(i, 0, n) {
			int t = max(0, (int)floor(sqrt(1.0 + d[i] * 4.0 / mi) - s[i] - 0.5) + 1);
			sum += (d[i] * 1.0 / (s[i] + t));
			total += t;
		}
		if (total >= x) {
			lo = mi;
			ans = sum + (total - x) * mi;
		} else {
			hi = mi;
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}

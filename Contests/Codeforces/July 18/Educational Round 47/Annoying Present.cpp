#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

ll g(ll n) { return (n * (n + 1)) >> 1; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	ll sum = 0;
	fori(i, 0, m) {
		int x, d; cin >> x >> d;
		sum += x * n;
		if (d > 0) {
			sum += g(n - 1) * d;
		} else {
			sum += 2 * g(n / 2) * d;
			if (n % 2 == 0) sum -= (n / 2) * d;
		}
	}
	double ans = sum * 1.0 / n;
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}

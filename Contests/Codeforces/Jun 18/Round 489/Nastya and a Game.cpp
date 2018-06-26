#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const double mx = 60.0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	vi a(n);
	fori(i, 1, n)
		a[i] = (v[i - 1] == 1 ? a[i - 1] + 1 : 0);
	int ans = 0;
	fori(i, 0, n) {
		int j = i;
		ll p = 1, s = 0;
		double lg = 0.0;
		while (j >= 0) {
			double c = log2(v[j]);
			if (lg + c > mx) break;
			lg += c;
			p *= v[j];
			s += v[j];
			ans += (p == s * k);
			ans += (p % k == 0 && 0 < p / k - s && p / k - s <= a[j]);
			s += a[j];
			j -= a[j] + 1;
		}
	}
	cout << ans << endl;
	return 0;
}

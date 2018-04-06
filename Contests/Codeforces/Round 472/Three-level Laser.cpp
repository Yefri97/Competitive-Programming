#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 110;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, lim; cin >> n >> lim;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	double ans = -1;
	fori(i, 0, n - 2) {
		int j = i + 1;
		int k = upper_bound(v.begin(), v.end(), lim + v[i]) - v.begin(); k--;
		if (j < k)
			ans = max(ans, 1.0 * (v[k] - v[j]) / (v[k] - v[i]));
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}

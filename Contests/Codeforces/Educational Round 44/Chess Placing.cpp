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
	int n; cin >> n;
	vi v(n / 2);
	fori(i, 0, n / 2)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans = oo;
	fori(k, 0, 2) {
		int c = 0;
		fori(i, 0, n / 2)
			c += abs((v[i] - 1) - (2 * i + k));
		ans = min(ans, c);
	}
	cout << ans << endl;
	return 0;
}

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
	int r, c;
	while (cin >> r >> c && (r || c)) {
		int n = r, m = c;
		if (n > m) swap(n, m);
		int ans;
		if (n == 1) {
			ans = m;
		} else if (n == 2) {
			ans = 4 * ((m + 3) / 4 - 1);
			if (m % 4 == 1) ans += 2;
			else ans += 4;
		} else {
			ans = (n * m + 1) / 2;
		}
		cout << ans << " knights may be placed on a " << r << " row " << c << " column board." << endl;
	}
	return 0;
}

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
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vi ans(n, 1);
		if (n == 1) {
			ans[0] = k;
		} else if (k == 2) {
			ans[0] = 2;
		} else if (k == 3) {
			ans[0] = (n % 2) ? 3 : 2;
		} else if (k > 3) {
			int d = log2(k);
			ans[0] = (1 << d);
			ans[1] = (1 << d) - 1;
			if (n % 2) ans[1] ^= 1;
		}
		fori(i, 0, n)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}

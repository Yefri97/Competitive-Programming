#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 2e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	vi a(32);
	fori(i, 0, n) {
		int x; cin >> x;
		int d = log2(x);
		a[d]++;
	}
	while (q--) {
		int x; cin >> x;
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			int k = min(x >> i, a[i]);
			x -= k * (1 << i);
			ans += k;
		}
		cout << (x > 0 ? -1 : ans) << endl;
	}
	return 0;
}

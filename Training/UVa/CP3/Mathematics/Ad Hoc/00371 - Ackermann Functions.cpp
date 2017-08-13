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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int l, r;
	while (cin >> l >> r && l) {
		int ans = 0, id = -1;
		if (r < l) swap(l, r);
		for (int i = l; i <= r; i++) {
			int cnt = 0;
			ll x = i;
			while (true) {
				x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
				cnt++;
				if (x == 1) break;
			}
			if (cnt > ans) {
				ans = cnt;
				id = i;
			}
		}
		cout << "Between " << l << " and " << r << ", " << id << " generates the longest sequence of " << ans << " values." << endl;
	}
	return 0;
}
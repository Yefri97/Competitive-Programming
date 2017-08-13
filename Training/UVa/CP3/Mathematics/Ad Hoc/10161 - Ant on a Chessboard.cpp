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
	int n;
	while (cin >> n && n) {
		int k = sqrt(n - 1) * 0.5, z = sq(k * 2) + 1;
		ii ans;
		int x = 1, y = 2 * k + 1;
		for (int i = 0; true; i++, x++, z++) {
			if (z == n) ans = ii(x, y);
			if (i == 2 * k) break;
		}
		for (int i = 0; true; i++, y--, z++) {
			if (z == n) ans = ii(x, y);
			if (i == 2 * k) break;
		}
		x++; z++;
		for (int i = 0; true; i++, y++, z++) {
			if (z == n) ans = ii(x, y);
			if (i == 2 * k + 1) break;
		}
		for (int i = 0; true; i++, x--, z++) {
			if (z == n) ans = ii(x, y);
			if (i == 2 * k + 1) break;
		}
		cout << ans.second << " " << ans.first << endl;
	}
	return 0;
}
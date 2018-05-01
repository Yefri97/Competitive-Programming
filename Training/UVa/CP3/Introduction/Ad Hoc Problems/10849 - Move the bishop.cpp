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
	int tc; cin >> tc;
	while (tc--) {
		int t, n; cin >> t >> n;
		while (t--) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			if (y2 % 2 == y1 % 2 && x2 % 2 == x1 % 2 || y2 % 2 != y1 % 2 && x2 % 2 != x1 % 2) {
				int ans;
				if (x1 == x2 && y1 == y2) ans = 0;
				else if (abs(x1 - x2) == abs(y1 - y2)) ans = 1;
				else ans = 2;
				cout << ans << endl;
			} else {
				cout << "no move" << endl;
			}
		}
	}
	return 0;
}

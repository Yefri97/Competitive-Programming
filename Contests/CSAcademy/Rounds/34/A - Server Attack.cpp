#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int state = 1, prev, ans = 0;
	while (n--) {
		int q, t; cin >> q >> t;
		if (q == 1) {
			if (state == 1) {
				state = 0;
				prev = t;
			}
		} else {
			if (state == 0) {
				state = 1;
				ans += t - prev;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
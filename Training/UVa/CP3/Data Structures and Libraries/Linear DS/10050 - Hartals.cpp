// 1D Array Manipulation
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

const int INF = 1e9, MAXN = 3660;

bitset<MAXN> bs;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, p; cin >> n >> p;
		bs.reset();
		for (int j = 6; j <= n; j += 7) {
			bs.set(j);
			bs.set(j + 1);
		}
		int target = 0;
		fori(i, 0, p) {
			int x; cin >> x;
			for (int j = x; j <= n; j += x) {
				if (!bs.test(j)) {
					bs.set(j);
					target++;
				}
			}
		}
		cout << target << endl;
	}
	return 0;
}
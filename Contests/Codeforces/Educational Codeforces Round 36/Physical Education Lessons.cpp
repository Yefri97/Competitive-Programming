#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;

	int ans = n;
	set<ii> intervals;

	while (q--) {

		int L, R, k; cin >> L >> R >> k;

		if (k == 1) {

			auto it = intervals.lower_bound(ii(L, 0));

			while (it != intervals.end()) {

				ii curr = *it;
				if (curr.second > R)
					break;

				ans += (curr.first - curr.second) + 1;
				intervals.erase(it++);

				L = min(L, curr.second);
				R = max(R, curr.first);

			}

			intervals.insert(ii(R, L));
			ans -= (R - L) + 1;

		} else {

			auto it = intervals.lower_bound(ii(L, 0));

			while (it != intervals.end()) {
				
				ii curr = *it;
				if (curr.second > R)
					break;

				ans += (curr.first - curr.second) + 1;
				intervals.erase(it++);

				if (L - 1 >= curr.second) {
					intervals.insert(ii(L - 1, curr.second));
					ans -= L - curr.second;
				}

				if (curr.first >= R + 1) {
					intervals.insert(ii(curr.first, R + 1));
					ans -= curr.first - R;
				}

			}

		}

		cout << ans << endl;
	}
	return 0;
}
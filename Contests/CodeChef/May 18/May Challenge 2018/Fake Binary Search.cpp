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
		int n, q; cin >> n >> q;
		map<int, int> pos;
		vi v(n);
		fori(i, 0, n) {
			cin >> v[i];
			pos[v[i]] = i;
		}
		vi s = v;
		sort(s.begin(), s.end());
		while (q--) {
			int x; cin >> x;
			int p = pos[x], a = 0, b = 0, l = 0, g = 0;
			int lo = 0, hi = n - 1;
			while (lo <= hi) {
				int mi = (lo + hi) / 2;
				if (mi == p) {
					break;
				} else if (mi < p) {
					a += (v[mi] > x);
					lo = mi + 1;
				} else {
					b += (v[mi] < x);
					hi = mi - 1;
				}
				l += (v[mi] < x);
				g += (v[mi] > x);
			}
			int k = lower_bound(s.begin(), s.end(), x) - s.begin();
			int c = min(a, b);
			if (a - c > k - l || b - c > (n - k - 1) - g)
				cout << -1 << endl;
			else
				cout << max(a, b) << endl;
		}
	}
	return 0;
}

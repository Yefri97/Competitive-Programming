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
		vi v(n);
		fori(i, 0, n)
			cin >> v[i];
		vi p(n);
		fori(i, 0, n)
			p[i] = i + 1;
		int ans = 0;
		do {
			int ok = 1;
			fori(i, 0, n)
				ok &= (v[i] == 0 || p[i] == v[i]);
			int c = 0;
			fori(i, 1, n)
				c += (p[i] > p[i - 1]);
			ans += (ok && c == k);
		} while (next_permutation(p.begin(), p.end()));
		cout << ans << endl;
	}
	return 0;
}

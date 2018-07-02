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
	int n, s; cin >> n >> s; s--;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	int l = (s - 1 + n) % n, r = s, curr = 0;
	ll ans = 0, d = 0;
	fori(i, 0, n - 1) {
		if (curr) {
			int x = d + a[l], nl = (l - 1 + n) % n;
			int y = a[r], nr = (r + 1) % n;
			if (x < y || x == y && nl < nr) {
				d += a[l];
				ans += x;
				curr = 0;
				l = nl;
			} else {
				d += a[r];
				ans += y;
				r = nr;
			}
		} else {
			int x = d + a[r], nr = (r + 1) % n;
			int y = a[l], nl = (l - 1 + n) % n;
			if (x < y || x == y && nr < nl) {
				d += a[r];
				ans += x;
				curr = 1;
				r = nr;
			} else {
				d += a[l];
				ans += y;
				l = nl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vi a(n), f(n + 1);
	fori(i, 0, n)
		cin >> a[i];
	int mx = 0;
	for (int l = 0, r = 0, c = 0; l < n; l++) {
		while (r < n && r - l < k) {
			if (f[a[r]] == 0)
				c++;
			f[a[r]]++;
			mx = max(mx, c);
			r++;
		}
		if (f[a[l]] == 1)
			c--;
		f[a[l]]--;
	}
	ll ans = 1;
	for (int l = 0, r = 0, c = 0; l < n; l++) {
		while (r < n && r - l < k) {
			if (f[a[r]] == 0) {
				ans = (ans * (mx - c)) % MD;
				c++;
			}
			f[a[r]]++;
			r++;
		}
		if (f[a[l]] == 1)
			c--;
		f[a[l]]--;
	}
	cout << ans << endl;
	return 0;
}

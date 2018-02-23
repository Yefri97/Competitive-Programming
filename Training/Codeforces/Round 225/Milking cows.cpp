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
	int n; cin >> n;
	vi v(n), a(n), b(n), c(n);
	fori(i, 0, n)
		cin >> v[i];
	fori(i, 1, n) {
		a[n - i - 1] = a[n - i] + (1 - v[n - i]);
		b[i] = b[i - 1] + v[i - 1];
	}
	fori(i, 0, n) {
		c[i] = a[i] + b[i];
		cout << c[i] << " ";
	}
	cout << endl;
	int ans = 0;
	for (int i = 0, l = 0, r = n - 1, d = 0; i < n; i++) {
		if (c[l] < c[r]) {
			ans += c[l] - d;
			if (v[l] == 1) d++;
			l++;
		} else if (c[l] > c[r]) {
			ans += c[r] - d;
			if (v[r] == 0) d++;
			r--;
		} else {
			if (v[l] == 1) {
				ans += c[l] - d;
				d++;
				l++;
			} else if (v[r] == 0) {
				ans += c[r] - d;
				d++;
				r--;
			} else {
				ans += c[l] - d;
				l++;
			}
		}
		debug(ans);
		debug(d);
	}
	cout << ans << endl;
	return 0;
}
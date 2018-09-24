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
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	fori(i, 0, n) {
		int x = a[i], ok = 0;
		fori(d, 0, 31) if ((1 << d) > x) {
			int y = (1 << d) - x;
			if (y != x) {
				if (binary_search(a.begin(), a.end(), y))
					ok = 1;
			} else {
				if (i - 1 >= 0 && a[i - 1] == x || i + 1 < n && a[i + 1] == x)
					ok = 1;
			}
			if (ok) break;
		}
		ans += ok;
	}
	cout << n - ans << endl;
	return 0;
}

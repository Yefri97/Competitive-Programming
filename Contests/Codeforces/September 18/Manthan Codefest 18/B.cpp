#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, s; cin >> n >> s;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	int m = n / 2;
	ll ans = 0;
	if (a[m] < s) {
		fori(i, m, n)
			ans += max(0, s - a[i]);
	} else if (a[m] > s) {
		fori(i, 0, m + 1)
			ans += max(0, a[i] - s);
	}
	cout << ans << endl;
	return 0;
}

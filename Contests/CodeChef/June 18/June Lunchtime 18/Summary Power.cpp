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
		string s; cin >> s;
		vi a(n);
		fori(i, 0, n - 1)
			a[i] = (s[i] == s[i + 1]);
		ll ans = 1LL * (n - k) * k, sum = 0;
		for (int l = 0, r = 0; r < n - 1; l++) {
			while (r - l < k) sum += a[r++];
			ans -= sum;
			sum -= a[l];
		}
		cout << ans << endl;
	}
	return 0;
}
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
	int k; cin >> k;
	string s; cin >> s;
	int n = s.size();
	vi v(n + 1);
	fori(i, 1, n + 1)
		v[i] += (s[i - 1] - '0') + v[i - 1];
	ll ans = 0;
	if (k == 0) {
		fori(i, 1, n + 1) {
			int r = upper_bound(v.begin(), v.end(), v[i - 1]) - v.begin();
			ans += r - i;
		}
	} else {
		fori(i, 1, n + 1) {
			int l = lower_bound(v.begin(), v.end(), k + v[i - 1]) - v.begin();
			int r = upper_bound(v.begin(), v.end(), k + v[i - 1]) - v.begin();
			ans += r - l;
		}
	}
	cout << ans << endl;
	return 0;
}

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
	int n, k; cin >> n >> k;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans;
	if (k == 0) {
		if (v[0] > 1) ans = 1;
		else ans = -1;
	} else if (k == n) {
		ans = v[n - 1];
	} else {
		int x = v[k - 1];
		if (v[k] == x) ans = -1;
		else ans = x;
	}
	cout << ans << endl;
	return 0;
}

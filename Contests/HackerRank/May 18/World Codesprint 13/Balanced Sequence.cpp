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
	string s; cin >> s;
	int sum = 0, mmin = 0;
	fori(i, 0, n) {
		sum += (s[i] == '(' ? 1 : -1);
		mmin = min(mmin, sum);
	}
	int ans = 0;
	if (mmin == 0) {
		ans = (sum > 0);
	} else {
		ans += (sum != mmin && sum - 2 * mmin > 0) + 1;
	}
	cout << ans << endl;
	return 0;
}

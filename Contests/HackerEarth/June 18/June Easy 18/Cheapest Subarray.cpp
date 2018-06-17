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
		int n; cin >> n;
		vi v(n);
		fori(i, 0, n)
			cin >> v[i];
		int ans = oo;
		fori(i, 1, n)
			ans = min(ans, v[i] + v[i - 1]);
		cout << ans << endl;
	}
	return 0;
}

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
	int n; cin >> n;
	vi l(n), r(n);
	fori(i, 0, n)
		cin >> l[i] >> r[i];
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int ans = 0;
	ans = max(ans, r[1] - l[n - 1]);
	ans = max(ans, r[0] - l[n - 2]);
	cout << ans << endl;
	return 0;
}
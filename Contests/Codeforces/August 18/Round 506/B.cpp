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
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	int ans = 0, cnt = 1;
	fori(i, 1, n) {
		if (a[i] <= 2 * a[i - 1])
			cnt++;
		else
			cnt = 1;
		ans = max(ans, cnt);
	}
	ans = max(ans, cnt);
	cout << ans << endl;
	return 0;
}

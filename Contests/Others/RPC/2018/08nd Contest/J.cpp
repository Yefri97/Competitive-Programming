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
	vector<ll> a(3), b(3), ans(3);
	fori(i, 1, n + 1) {
		int x; cin >> x;
		a[i % 3] += x;
	}
	fori(i, 1, n + 1) {
		int x; cin >> x;
		b[i % 3] += x;
	}
	fori(i, 0, 3)
		fori(j, 0, 3)
			ans[(i + j) % 3] += a[i] * b[j];
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	return 0;
}

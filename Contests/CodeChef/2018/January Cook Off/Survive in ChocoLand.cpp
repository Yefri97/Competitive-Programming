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
		int n, k, s; cin >> n >> k >> s;
		int ans = ((6 * (s / 7) + s % 7) * n < k * s) ? -1 : (k * s + n - 1) / n;
		cout << ans << endl;
	}
	return 0;
}
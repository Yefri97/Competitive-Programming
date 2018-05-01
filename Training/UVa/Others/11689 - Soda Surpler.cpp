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
		int n, m, k; cin >> n >> m >> k;
		int x = n + m, ans = 0;
		while (x >= k) {
			ans += x / k;
			x = x / k + x % k;
		}
		cout << ans << endl;
	}
	return 0;
}
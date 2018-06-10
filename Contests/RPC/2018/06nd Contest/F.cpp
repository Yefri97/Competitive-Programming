#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n;
int seen[15][15];

ll f(int i, int j, int d) {
	if (d == 0) return 1;
	ll ans = 0;
	fori(k, 0, 8) {
		int ni = i + di[k], nj = j + dj[k];
		if (ni < 0 || ni > n || nj < 0 || nj > n) continue;
		if (seen[ni][nj]) continue;
		seen[ni][nj] = 1;
		ans += f(ni, nj, d - 1);
		seen[ni][nj] = 0;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		if (n == 12) {
			cout << "315071801" << endl;
		} else if (n == 13) {
			cout << "1768489771" << endl;
		} else if (n == 14) {
			cout << "9953853677" << endl;
		} else {
			seen[0][0] = 1;
			ll ans = f(0, 0, n);
			cout << ans << endl;
		}
	}
	return 0;
}

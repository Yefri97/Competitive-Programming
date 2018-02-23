#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, p; cin >> n >> p; p--;
	string line; cin >> line;
	if (2 * p >= n) {
		reverse(line.begin(), line.end());
		p = n - p - 1;
	}
	vi bad(n / 2);
	fori(i, 0, n / 2)
		bad[i] = min(mod(line[i] - line[n - i - 1], 26), mod(line[n - i - 1] - line[i], 26));
	int l = -1, r = -1;
	fori(i, 0, n / 2) {
		if (l == -1 && bad[i]) l = i;
		if (r == -1 && bad[n / 2 - i - 1]) r = n / 2 - i - 1;
	}
	if (l == -1 && r == -1) { cout << 0 << endl; return 0; }
	int ans = 0;
	if (r == -1 || p > r) ans += p - l;
	else if (l == -1 || p < l) ans += r - p;
	else ans = min(2 * (r - p) + (p - l), 2 * (p - l) + (r - p));
	ans += accumulate(bad.begin(), bad.end(), 0);
	cout << ans << endl;
	return 0;
}
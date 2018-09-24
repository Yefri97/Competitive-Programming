#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 10;

ll pt10[MX];
map<int, int> mapper[MX];

int d(int x) { return floor(log10(x)) + 1; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	pt10[0] = 1;
	fori(i, 1, MX)
		pt10[i] = 10 * pt10[i - 1];
	int n, k; cin >> n >> k;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 0, n)
		mapper[d(a[i])][a[i] % k]++;
	int ans = 0;
	fori(i, 0, MX) {
		fori(j, 0, n) {
			int x = (a[j] * pt10[i]) % k;
			ans += mapper[i][(k - x) % k];
		}
	}
	fori(i, 0, n)
		ans -= ((a[i] * pt10[d(a[i])] + a[i]) % k == 0);
	cout << ans << endl;
	return 0;
}

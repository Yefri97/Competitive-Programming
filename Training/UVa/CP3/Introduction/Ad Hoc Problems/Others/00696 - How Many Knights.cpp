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

	int nn, mm;
	while (cin >> nn >> mm && (nn || mm)) {
		int n = nn, m = mm;
		if (n > m)
			swap(n, m);
		int ans;
		if (n == 0) {
			ans = 0;
		} else if (n == 1) {
			ans = m;
		} else if (n == 2) {
			ans = 4 * ((m + 3) / 4) - ((m - 1) % 4 == 0 ? 2 : 0);
		} else {
			ans = (n * m + 1) / 2;
		}
		cout << ans << " knights may be placed on a " << nn << " row " << mm << " column board." << endl;
	}
	return 0;
}
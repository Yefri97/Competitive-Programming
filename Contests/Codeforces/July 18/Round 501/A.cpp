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
	int n, m; cin >> n >> m;
	vi l(n), r(n);
	fori(i, 0, n)
		cin >> l[i] >> r[i];
	int ans = m;
	vi c(m + 1);
	fori(i, 1, m + 1) {
		fori(j, 0, n) {
			if (l[j] <= i && i <= r[j]) {
				ans--;
				c[i] = 1;
				break;
			}
		}
	}
	cout << ans << endl;
	fori(i, 1, m + 1) if (!c[i])
		cout << i << " ";
	cout << endl;
	return 0;
}

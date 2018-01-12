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
	int n;
	while (cin >> n) {
		vi v(n);
		fori(i, 0, n)
			cin >> v[i];
		fori(i, 1, n)
			v[i] += v[i - 1];
		int ans = oo;
		fori(i, 0, n) {
			fori(j, 0, i + 1) {
				int sum = v[i] - (j ? v[j - 1] : 0);
				ans = min(ans, abs(360 - 2 * sum));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
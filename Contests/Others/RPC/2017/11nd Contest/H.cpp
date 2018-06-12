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
		n = unique(v.begin(), v.end()) - v.begin();
		if (n == 1) {
			cout << (v[0] != 0) << endl;
		} else {
			int ans = v[1] < v[0];
			fori(i, 1, n - 1)
				ans += v[i - 1] < v[i] && v[i + 1] < v[i];
			ans += v[n - 2] < v[n - 1];
			cout << ans << endl;
		}
	}
	return 0;
}
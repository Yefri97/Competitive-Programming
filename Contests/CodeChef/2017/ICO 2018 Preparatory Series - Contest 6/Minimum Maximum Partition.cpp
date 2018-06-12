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
	int n, k; cin >> n >> k;
	vi v(n), c(n - 1);
	fori(i, 0, n)
		cin >> v[i];
	fori(i, 0, n - 1)
		c[i] = v[i] + v[i + 1];
	sort(c.begin(), c.end());
	ll min_val, max_val;
	min_val = max_val = v[0] + v[n - 1];
	fori(i, 0, k - 1) {
		min_val += c[i];
		max_val += c[(n - 1) - i - 1];
	}
	cout << min_val << " " << max_val << endl;
	return 0;
}
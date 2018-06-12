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
	int n, a, b; cin >> n >> a >> b;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	vi ans(n);
	int l = 0, r = 0, limit = v[l] + b;
	while (l < n) {
		while (r < n && v[r] <= limit && r - l < a) r++;
		int k = r - l;
		fori(i, 0, (k + 1) / 2) {
			ans[l] = k == a ? v[r - 1] : limit;
			l++;
		}
		limit = v[l] + b;
	}
	cout << ans[0];
	fori(i, 1, n)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
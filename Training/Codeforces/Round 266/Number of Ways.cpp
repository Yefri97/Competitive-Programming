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
	int n; cin >> n;
	vector<ll> v(n);
	fori(i, 0, n)
		cin >> v[i];
	ll acc = accumulate(v.begin(), v.end(), 0LL);
	if (acc % 3 != 0) { cout << 0 << endl; return 0; }
	vi first, second;
	ll x = acc / 3, sum = 0;
	fori(i, 0, n - 1) {
		sum += v[i];
		if (sum == x)
			first.push_back(i);
		if (sum == 2 * x)
			second.push_back(i);
	}
	ll ans = 0;
	fori(i, 0, (int)first.size())
		ans += second.end() - upper_bound(second.begin(), second.end(), first[i]);;
	cout << ans << endl;
	return 0;
}
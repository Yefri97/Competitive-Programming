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
	ll n, k;
	while (cin >> n >> k) {
		ll min_val = (k == 0 || k == n ? 0 : 1);
		ll max_val = (3 * k > n ? n - k : 2 * k);
		cout << min_val << " " << max_val << endl;
	}
	return 0;
}
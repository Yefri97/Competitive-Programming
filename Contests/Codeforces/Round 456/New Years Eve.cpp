#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin >> n >> k;
	if (k == 1) {
		cout << n << endl;
	} else {
		int cnt = 0;
		while (n) {
			n >>= 1;
			cnt++;
		}
		ll ans = (1LL << cnt) - 1;
		cout << ans << endl;
	}
	return 0;
}
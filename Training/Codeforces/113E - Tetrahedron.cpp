#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, kmod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	ll d = 1, abc = 0;
	fori(i, 0, n) {
		ll nd = (abc * 3LL) % kmod;
		ll nabc = (abc * 2LL + d) % kmod;
		d = nd;
		abc = nabc;
	}
	cout << d << endl;
	return 0;
}
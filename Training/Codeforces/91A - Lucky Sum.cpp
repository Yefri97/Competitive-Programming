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

const int oo = 1e9;

vector<ll> lucky;

void gen(int k, string num) {
	if (k == 0) { lucky.push_back(atoi(num.c_str())); return; }
	gen(k - 1, num + "4");
	gen(k - 1, num + "7");
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	lucky.push_back(0);
	fori(i, 1, 10)
		gen(i, "");
	lucky.push_back(4444444444);
	ll l, r; cin >> l >> r;
	ll ans = 0;
	fori(i, 1, lucky.size()) {
		if (lucky[i] >= l && lucky[i - 1] <= r)
			ans += (lucky[i] * (min(r, lucky[i]) - max(l - 1, lucky[i - 1])));
	}
	cout << ans << endl;
	return 0;
}
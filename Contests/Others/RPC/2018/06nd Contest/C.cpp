#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int r, k; cin >> r >> k;
		ll ans = (k % 2 ? (1LL << ((k - 1) >> 1)) : (1LL << ((k + 2) >> 1)));
		cout << ans * r * r;
		if (k % 2) cout << "PI";
		cout << endl;
	}
	return 0;
}

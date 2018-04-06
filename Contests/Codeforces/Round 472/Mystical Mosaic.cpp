#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 110;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	set<ll> dict;
	fori(i, 0, n) {
		ll bs = 0;
		fori(j, 0, m) {
			char c; cin >> c;
			if (c == '#') bs |= 1LL << j;
		}
		dict.insert(bs);
	}
	int ans = 1;
	fori(i, 0, m) {
		int cnt = 0;
		for (ll bs : dict) cnt += (bs >> i) & 1;
		if (cnt > 1) ans = 0;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

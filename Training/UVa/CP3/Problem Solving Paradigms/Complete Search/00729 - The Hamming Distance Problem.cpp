#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n, h; cin >> n >> h;
		vi ans;
		fori(i, 0, (1 << n)) {
			if (__builtin_popcount(i) == h)
				ans.push_back(i);
		}
		for (int x : ans) {
			fori(j, 0, n)
				cout << ((x >> (n - j - 1)) & 1);
			cout << endl;
		}
		if (tc) cout << endl;
	}
	return 0;
}

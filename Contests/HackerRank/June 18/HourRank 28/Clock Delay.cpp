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
	int q; cin >> q;
	while (q--) {
		int h1, m1, h2, m2; cin >> h1 >> m1 >> h2 >> m2;
		int k; cin >> k;
		int ans = ((h1 + k) * 60 + m1) - (h2 * 60 + m2);
		cout << ans << endl;
	}
	return 0;
}

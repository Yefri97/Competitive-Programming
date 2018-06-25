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
	int n; cin >> n;
	vi l;
	map<int, int> r;
	fori(i, 0, n) {
		string s; cin >> s;
		int m = 0, c = 0;
		for (char b : s) {
			c += (b == '(' ? 1 : -1);
			m = min(m, c);
		}
		if (m == 0)
			l.push_back(c);
		if (m == c)
			r[c]++;
	}
	ll ans = 0;
	for (int c : l)
		ans += r[-c];
	cout << ans << endl;
	return 0;
}

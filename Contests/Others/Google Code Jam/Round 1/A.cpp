#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<string, string> ii;

const int oo = 1e9;

string solve() {
	int n, m; cin >> n >> m;
	vector<ii> v(n);
	fori(i, 0, n) {
		string s; cin >> s;
		v[i].second = s;
		sort(s.begin(), s.end());
		v[i].first = s;
	}
	// if (m == 1) return "-";
	sort(v.begin(), v.end());
	fori(i, 0, n) {
		cout << v[i].first << endl;
	}
	return "-";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	fori(t, 0, tc) {
		string ans = solve();
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}

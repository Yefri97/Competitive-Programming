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
		vi v(4);
		fori(i, 0, 4)
			cin >> v[i];
		sort(v.begin(), v.end());
		string ans;
		if (v[0] == v[3]) ans = "square";
		else if (v[0] == v[1] && v[2] == v[3]) ans = "rectangle";
		else if (v[0] + v[1] + v[2] > v[3]) ans = "quadrangle";
		else ans = "banana";
		cout << ans << endl;
	}
	return 0;
}

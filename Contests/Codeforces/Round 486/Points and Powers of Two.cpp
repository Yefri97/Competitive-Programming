#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

set<int> dict;

vi solve() {
	ii ans = ii(-1, -1);
	fori(i, 0, 32) {
		int k = (1 << i);
		for (int x : dict) {
			int a = dict.count(x - k);
			int b = dict.count(x + k);
			if (a && b) return vi({x - k, x, x + k});
			if (a) ans = ii(x, x - k);
			if (b) ans = ii(x, x + k);
		}
	}
	if (ans.first != -1) return vi({ans.first, ans.second});
	return vi({*dict.begin()});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		dict.insert(x);
	}
	vi ans = solve();
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}

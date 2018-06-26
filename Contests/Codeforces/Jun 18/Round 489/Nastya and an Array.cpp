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
	set<int> dict;
	int zero = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		if (x == 0) zero = 1;
		dict.insert(x);
	}
	int ans = dict.size() - zero;
	cout << ans << endl;
	return 0;
}

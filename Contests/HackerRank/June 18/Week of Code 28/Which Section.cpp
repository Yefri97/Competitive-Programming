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
	int t; cin >> t;
	while (t--) {
		int n, k, m; cin >> n >> k >> m;
		vi v(m);
		fori(i, 0, m)
			cin >> v[i];
		fori(i, 1, m)
			v[i] += v[i - 1];
		int p = lower_bound(v.begin(), v.end(), k) - v.begin();
		cout << p + 1 << endl;
	}
	return 0;
}

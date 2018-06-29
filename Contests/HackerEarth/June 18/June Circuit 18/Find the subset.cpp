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
	int n, m, d; cin >> n >> m >> d;
	vector<ii> v(m);
	fori(i, 0, m) {
		int x; cin >> x;
		v[i] = ii(x, i);
	}
	sort(v.begin(), v.end());
	vector<ii> ans(n);
	fori(i, 0, n)
		ans[i] = ii(v[i].second, v[i].first);
	sort(ans.begin(), ans.end());
	fori(i, 0, n)
		cout << ans[i].second << " ";
	cout << endl;
	return 0;
}

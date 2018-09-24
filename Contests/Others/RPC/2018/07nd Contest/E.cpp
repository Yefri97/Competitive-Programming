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
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	vi ans(2);
	fori(i, 0, n)
		ans[i % 2] += v[i];
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}

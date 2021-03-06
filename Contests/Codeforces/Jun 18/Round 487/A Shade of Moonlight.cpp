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
	int n, l, w; cin >> n >> l >> w;
	vi plus, minus;
	fori(i, 0, n) {
		int x, v; cin >> x >> v;
		if (v == 1)
			plus.push_back(x);
		else
			minus.push_back(x);
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	ll ans = 0;
	for (int i = 0, j = 0; i < plus.size(); i++) {
		while (j < minus.size() && (minus[j] < plus[i] || 1LL * w * (minus[j] + l - plus[i]) <= abs(minus[j] + l + plus[i])))
			j++;
		ans += (minus.size() - j);
	}
	cout << ans << endl;
	return 0;
}

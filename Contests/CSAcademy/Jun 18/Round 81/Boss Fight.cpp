#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

ll ceil2(ll a, ll b) { return (a + b - 1) / b; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a1, l1, a2, l2; cin >> a1 >> l1 >> a2 >> l2;
	ll c, x, y; cin >> c >> x >> y;
	int ans = 0;
	fori(i, 0, c + 1)
		ans |= (ceil2(l2, a1 + i * x) <= ceil2(l1 + (c - i) * y, a2));
	cout << ans << endl;
	return 0;
}

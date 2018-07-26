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
	ll n, x, y; cin >> n >> x >> y;
	string s; cin >> s;
	ll cnt = (s[0] == '0');
	fori(i, 1, n)
		cnt += (s[i] == '0' && s[i - 1] == '1');
	ll ans = (cnt > 0 ? (cnt - 1) * min(x, y) + y : 0);
	cout << ans << endl;
	return 0;
}

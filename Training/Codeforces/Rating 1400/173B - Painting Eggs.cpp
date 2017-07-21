#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, k = 500;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int sa = 0, sb = 0;
	string ans;
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		if (abs((sa + a) - (sb)) <= k) sa += a, ans += "A";
		else sb += b, ans += "G";
	}
	if (abs(sa - sb) > k)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MOD = 1 << 30;

ll d(int n) {
	ll pf = 2, ans = 1;
	while (pf * pf <= n) {
		ll power = 0;
		while (n % pf == 0) { n /= pf; power++; }
		ans *= (power + 1);
		pf++;
	}
	if (n != 1) ans *= 2;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	ll ans = 0;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				ans = (ans + d(i * j * k)) % MOD;
	cout << ans << endl;
	return 0;
}
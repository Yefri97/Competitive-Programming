#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MN = 1e6 + 10;
const int MD = 1e9 + 7;

ll f[MN];

ll fastExp(ll b, ll e) {
	ll ans = 1;
	while (e > 0) {
		if (e & 1)
			ans = (ans * b) % MD;
		b = (b * b) % MD;
		e >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	f[0] = 1;
	fori(i, 1, MN)
		f[i] = (i * f[i - 1]) % MD;
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		ll p = f[a];
		ll q = (f[b] * f[a - b]) % MD;
		ll ans = (p * fastExp(q, MD - 2)) % MD;
		cout << ans << endl;
	}
	return 0;
}

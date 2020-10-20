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
const int MK = 60;

ll n;
ll memo[MK][2];

ll dp(bitset<MK> &bs, int i, int b) {
	if (i < 0) return 0;
	if (memo[i][b] != -1) return memo[i][b];
	ll ans = 0;
	fori(d, 0, (b ? 1 : bs[i]) + 1) {
		ll val = b ? (1LL << i) : n - ((n >> i) << i) + 1;
		ans += dp(bs, i - 1, b || d < bs[i]) + val * d;
	}
	return memo[i][b] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n;
	bitset<MK> bs(n);
	memset(memo, -1, sizeof memo);
	cout << dp(bs, MK - 1, 0) << endl;
	return 0;
}

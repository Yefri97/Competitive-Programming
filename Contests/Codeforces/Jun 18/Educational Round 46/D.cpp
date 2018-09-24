#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1010, MD = 998244353;

ll dp[MN], fact[MN];

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

ll comb(int n, int k) {
	ll p = fact[n];
	ll q = (fastExp(fact[k], MD - 2) * fastExp(fact[n - k], MD - 2)) % MD;
	return (p * q) % MD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	fori(i, 1, MN)
		fact[i] = (i * fact[i - 1]) % MD;
	int n; cin >> n;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) if (a[i] > 0)
		for (int j = i + a[i] + 1; j <= n; j++)
			dp[i] = (dp[i] + comb(j - i - 1, a[i]) * dp[j]) % MD;
	int ans = 0;
	fori(i, 0, n)
		ans = (ans + dp[i]) % MD;
	cout << ans << endl;
	return 0;
}

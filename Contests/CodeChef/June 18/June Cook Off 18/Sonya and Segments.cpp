#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 400010, MD = 1e9 + 7;

ll fact[MN];

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
	if (n < k) return 0;
	ll p = fact[n];
	ll q = (fastExp(fact[k], MD - 2) * fastExp(fact[n - k], MD - 2)) % MD;
	return (p * q) % MD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	fori(i, 1, MN)
		fact[i] = (i * fact[i - 1]) % MD;
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<ii> v(n);
		fori(i, 0, n)
			cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end());
		multiset<int> dict;
		ll ans = comb(n, k);
		fori(i, 0, n) {
			while (dict.size() > 0) {
				auto it = dict.begin();
				if (*(it) >= v[i].first) break;
				dict.erase(it);
			}
			ll p = dict.size();
			ans = (ans - comb(p, k - 1) + MD) % MD;
			dict.insert(v[i].second);
		}
		cout << ans << endl;
	}
	return 0;
}

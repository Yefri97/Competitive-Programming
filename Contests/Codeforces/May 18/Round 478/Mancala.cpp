#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

const int oo = 1e9, k = 14;

ll check(vi v, int s) {
	ll x = v[s];
	v[s] = 0;
	ll p = x / k;
	fori(i, 0, k) v[i] += p;
	ll q = x % k;
	fori(i, 0, q) v[(s + i + 1) % k]++;
	ll ans = 0;
	fori(i, 0, k) if (v[i] % 2 == 0)
		ans += v[i];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi v(k);
	fori(i, 0, k)
		cin >> v[i];
	ll ans = 0;
	fori(i, 0, k) if (v[i] > 0)
		ans = max(ans, check(v, i));
	cout << ans << endl;
	return 0;
}

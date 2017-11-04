ll comb(ll n, ll k) {
	ll ans = 1;
	for (ll i = 1; i <= k; i++, n--) {
		ans *= n;
		ans /= i;
	}
	return ans;
}
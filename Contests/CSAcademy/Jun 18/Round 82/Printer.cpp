#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n = 4;
	vi need(n), price(n);
	fori(i, 0, n)
		cin >> need[i];
	fori(i, 0, n)
		cin >> price[i];
	ll c; cin >> c;
	fori(i, 0, n) fori(j, 1, n) {
		if (need[j] < need[j - 1]) {
			swap(need[j], need[j - 1]);
			swap(price[j], price[j - 1]);
		}
	}
	ll ans = 0;
	ll sum = accumulate(price.begin(), price.end(), 0);
	fori(i, 0, n) {
		if (sum > c) {
			ans += (need[i] * c);
			fori(j, i + 1, n)
				need[j] -= need[i];
		} else {
			ans += (need[i] * price[i]);
		}
		sum -= price[i];
	}
	cout << ans << endl;
	return 0;
}

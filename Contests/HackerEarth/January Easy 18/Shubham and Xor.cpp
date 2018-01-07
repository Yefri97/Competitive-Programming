#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<int, int> mapper;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mapper[x]++;
	}
	ll ans = 0;
	for (auto x : mapper) {
		ll cnt = x.second;
		ans += ((cnt * (cnt - 1)) / 2);
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod_pow(int b, int p, int m) {
	if (p == 0) return 1;
	ll ans = mod_pow(b, p / 2, m); ans = (ans * ans) % m;
	if (p % 2) ans = (ans * b) % m;
	return ans;
}

int main() {
	int b, p, m;
	while (cin >> b >> p >> m) {
		ll ans = mod_pow(b, p, m);
		cout << ans << endl;
	}
	return 0;
}
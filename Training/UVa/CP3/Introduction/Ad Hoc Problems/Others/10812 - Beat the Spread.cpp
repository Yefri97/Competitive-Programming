#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n; cin >> n;
	while (n--) {
		ll s, d; cin >> s >> d;
		if (s >= d && (s + d) % 2 == 0) {
			ll a = (s + d) / 2, b = (s - d) / 2;
			cout << a << " " << b << endl;
		} else
			cout << "impossible" << endl;
	}
	return 0;
}
// Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		long long x; cin >> x;
		long long msb = 1;
		while (msb <= x) msb <<= 1;
		long long ans = x ^ (msb - 1);
		cout << ans << endl;
	}
	return 0;
}
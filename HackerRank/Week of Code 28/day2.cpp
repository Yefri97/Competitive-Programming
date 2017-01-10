// Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		long long x; cin >> x;
		long long ans = 0;
		for (int i = 0; (1 << i) < x; i++) {
			if ((x & (1 << i)) == 0)
				ans |= (1 << i);
		}
		cout << ans << endl;
	}
	return 0;
}
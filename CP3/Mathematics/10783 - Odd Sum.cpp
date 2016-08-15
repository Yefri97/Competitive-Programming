#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cout << "Case " << tt + 1 << ": ";
		int a, b; cin >> a >> b;
		int ans = 0;
		for (int i = a; i <= b; i++) if (i % 2) ans += i;
		cout << ans << endl;
	}
	return 0;
}
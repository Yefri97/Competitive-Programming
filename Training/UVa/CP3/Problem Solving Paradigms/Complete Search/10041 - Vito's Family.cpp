#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int v[510], ans = 100000000;
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> v[i];
		for (int i = 0; i < n; i++) {
			int x = 0;
			for (int j = 0; j < n; j++) x += abs(v[i] - v[j]);
			ans = min(ans, x);
		}
		cout << ans << endl;
	}
	return 0;
}
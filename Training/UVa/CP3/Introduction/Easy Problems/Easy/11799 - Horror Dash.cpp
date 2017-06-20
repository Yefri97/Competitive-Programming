// Easy Problems
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, cs = 1; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = -1;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			ans = max(ans, x);
		}
		cout << "Case " << cs++ << ": " << ans << endl;
	}
	return 0;
}
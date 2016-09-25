#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		multiset<int> ms;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			ms.insert(x);
		}
		int ans = n;
		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			multiset<int>::iterator it = ms.find(x);
			if (it != ms.end()) {
				ans--;
				ms.erase(it);
			}
			else
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
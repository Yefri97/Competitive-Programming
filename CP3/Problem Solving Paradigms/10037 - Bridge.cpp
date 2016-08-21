#include <bits/stdc++.h>
using namespace std;

int main() {
	bool first = true;
	int t; cin >> t;
	while (t--) {
		if (!first) cout << endl; first = false;
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < v.size(); i++) cin >> v[i];
		sort(v.begin(), v.end());
		if (n == 1) { cout << v[0] << endl << v[0] << endl; continue; }
		int ans = 0;
		for (int i = n - 1, a = v[0], b = v[1]; true; i -= 2) {
			int x = v[i - 1], y = v[i];
			if (i < 3) {
				if (i == 2) ans += b + a + y;
				if (i == 1) ans += b;
				break;
			}
			ans += min(2 * a + x + y, 2 * b + a + y);
		}
		cout << ans << endl;
		for (int i = n - 1, a = v[0], b = v[1]; true; i -= 2) {
			int x = v[i - 1], y = v[i];
			if (i < 3) {
				if (i == 2) {
					cout << a << " " << b << endl;
					cout << a << endl;
					cout << a << " " << y << endl;
				}
				if (i == 1) {
					cout << a << " " << b << endl;
				}
				break;
			}
			if (a + x < 2 * b) {
				cout << a << " " << x << endl;
				cout << a << endl;
				cout << a << " " << y << endl;
				cout << a << endl;
			} else {
				cout << a << " " << b << endl;
				cout << a << endl;
				cout << x << " " <<  y << endl;
				cout << b << endl;
			}
		}
	}
	return 0;
}
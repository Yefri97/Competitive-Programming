// Super Easy Problems
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	while (cin >> k) {
		int n, m; cin >> n >> m;
		while (k--) {
			int x, y; cin >> x >> y;
			if (x == n || y == m)
				cout << "divisa" << endl;
			else if (x < n) {
				if (y < m)
					cout << "SO" << endl;
				else
					cout << "NO" << endl;
			} else {
				if (y < m)
					cout << "SE" << endl;
				else
					cout << "NE" << endl;
			}
		}
	}
	return 0;
}
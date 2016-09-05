#include <bits/stdc++.h>

using namespace std;

int distance_to(int x, int y) {
	int n = x + y;
	int pos = (n * (n + 1)) / 2 + x;
	return pos;
}

int main() {
	int t, ct = 1; cin >> t;
	while (t--) {
		cout << "Case " << ct++ << ": ";
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int ans = distance_to(x2, y2) - distance_to(x1, y1);
		cout << ans << endl;
	}
	return 0;
}
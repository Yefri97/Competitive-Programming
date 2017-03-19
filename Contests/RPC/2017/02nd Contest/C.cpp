/*
 *  RPC 02st Contest 2017
 *  Problem C: Cameras
 *  Outcome: Accepted | Category: Sliding window
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, r; cin >> n >> k >> r;
	vector<int> cameras(n);
	while (k--) {
		int x; cin >> x; x--;
		cameras[x] = 1;
	}
	int ans = 0, window = 0;
	for (int i = 0; i < r; i++) window += cameras[i];
	for (int i = r - 1; i < n; i++) {
		if (window == 0) {
			cameras[i - 1] = 1;
			cameras[i] = 1;
			window += 2;
			ans += 2;
		} else if (window == 1) {
			if (cameras[i] == 0)
				cameras[i] = 1;
			else
				cameras[i - 1] = 1;
			window += 1;
			ans += 1;
		}
		window -= cameras[i - r + 1];
		window += cameras[i + 1];
	}
	cout << ans << endl;
	return 0;
}
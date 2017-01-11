// C++ STL queue
#include <bits/stdc++.h>
using namespace std;

const int LEFT = 0, RIGHT = 1;

int main() {
	int t; cin >> t;
	while (t--) {
		int l, n; cin >> l >> n;
		l *= 100;
		vector< queue<int> > vq(2);
		while (n--) {
			int m; cin >> m;
			string side; cin >> side;
			if (side == "left") vq[LEFT].push(m);
			else vq[RIGHT].push(m);
		}
		int ans = 0, sd = LEFT;
		while (!vq[LEFT].empty() || !vq[RIGHT].empty()) {
			int ld = 0;
			while (!vq[sd].empty() && ld + vq[sd].front() <= l) {
				ld += vq[sd].front();
				vq[sd].pop();
			}
			sd = 1 - sd;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
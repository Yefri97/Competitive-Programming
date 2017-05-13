#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> velocity(n);
		for (int i = 0; i < n; i++)
			cin >> velocity[i];
		sort(velocity.begin(), velocity.end());
		vector<ii> path;
		int ans = 0;
		int a = 0, b = 1, x = n - 2, y = n - 1;
		while (y > 2) {
			int va = velocity[a], vb = velocity[b], vx = velocity[x], vy = velocity[y];
			if (2 * va + vx + vy < va + 2 * vb + vy) {
				ans += 2 * va + vx + vy;
				path.push_back(ii(va, vy));
				path.push_back(ii(va, -1));
				path.push_back(ii(va, vx));
				path.push_back(ii(va, -1));
			} else {
				ans += va + 2 * vb + vy;
				path.push_back(ii(va, vb));
				path.push_back(ii(va, -1));
				path.push_back(ii(vx, vy));
				path.push_back(ii(vb, -1));
			}
			x -= 2; y -= 2;
		}
		if (y == 2) {
			ans += velocity[2] + velocity[0] + velocity[1];
			path.push_back(ii(velocity[0], velocity[2]));
			path.push_back(ii(velocity[0], -1));
			path.push_back(ii(velocity[0], velocity[1]));
		}
		if (y == 1) {
			ans += velocity[1];
			path.push_back(ii(velocity[0], velocity[1]));
		}
		if (y == 0) {
			ans += velocity[0];
			path.push_back(ii(velocity[0], -1));
		}
		cout << ans << endl;
		for (int i = 0; i < path.size(); i++) {
			cout << path[i].first;
			if (path[i].second != -1)
				cout << " " << path[i].second;
			cout << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}
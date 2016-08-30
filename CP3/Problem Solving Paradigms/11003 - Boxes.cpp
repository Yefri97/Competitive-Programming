#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, w[MAXN + 10], c[MAXN + 10], memo[3010][1010];

int box(int cap, int id) {
	if (id == n) return 0;
	if (memo[cap][id] != -1) return memo[cap][id];
	if (w[id] > cap) return memo[cap][id] = box(cap, id + 1);
	return memo[cap][id] = max(box(cap, id + 1), box(min(c[id], cap - w[id]), id + 1) + 1);
}

int main() {
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) cin >> w[i] >> c[i];
		memset(memo, -1, sizeof memo);
		int ans = -1;
		for (int i = 0; i < n; i++) {
			ans = max(ans, box(c[i], i + 1) + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
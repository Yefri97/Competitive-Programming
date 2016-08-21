#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int a[30], b[30], temp[30];
	for (int i = 0; i < n; i++) cin >> a[i];
	while (cin >> temp[0]) {
		for (int i = 1; i < n; i++) cin >> temp[i];
		for (int i = 0; i < n; i++) b[temp[i] - 1] = i + 1;
		int lcs[30][30]; memset(lcs, 0, sizeof lcs);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
		//for (int i = 0; i <= n; i++) { for (int j = 0; j <= n; j++) cout << lcs[i][j] << " "; cout << endl; }
		int ans = lcs[n][n];
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int temp_a[30], temp_b[30], a[30], b[30];
	for (int i = 0; i < n; i++) cin >> temp_a[i];
	while (cin >> temp_b[0]) {
		for (int i = 1; i < n; i++) cin >> temp_b[i];
		for (int i = 0; i < n; i++) a[temp_a[i] - 1] = i;
		for (int i = 0; i < n; i++) b[temp_b[i] - 1] = i;
		int lcs[30][30]; memset(lcs, 0, sizeof lcs);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i - 1] == b[j - 1]) 
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else 
					lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
		//for (int i = 0; i <= n; i++) { for (int j = 0; j <= n; j++) cout << lcs[i][j] << " "; cout << endl; }
		int ans = lcs[n][n];
		cout << ans << endl;
	}
	return 0;
}
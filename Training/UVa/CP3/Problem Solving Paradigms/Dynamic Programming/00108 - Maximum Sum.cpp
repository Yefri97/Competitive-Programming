#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	int A[110][110]; memset(A, 0, sizeof A);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			A[i][j] += A[i - 1][j];
			A[i][j] += A[i][j - 1];
			A[i][j] -= A[i - 1][j - 1];
		}
	int ans = -200;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		for (int k = i; k <= n; k++) for (int l = j; l <= n; l++) {
			int subRect = A[k][l];
			subRect -= A[i - 1][l];
			subRect -= A[k][j - 1];
			subRect += A[i - 1][j - 1];
			ans = max(ans, subRect);
		}
	cout << ans << endl;
	return 0;
}
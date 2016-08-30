#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;
int n, A[60], memo[60][60];

int cut(int left, int right) {
	if (left + 1 == right) return 0;
	if (memo[left][right] != -1) return memo[left][right];
	int ans = INF;
	for (int i = left + 1; i < right; i++)
		ans = min(ans, cut(left, i) + cut(i, right) + A[right] - A[left]);
	return memo[left][right] = ans;
}

int main() {
	int l;
	while (cin >> l && l) {
		cin >> n;
		A[0] = 0;
		for (int i = 0; i < n; i++) cin >> A[i + 1];
		A[n + 1] = l;
		memset(memo, -1, sizeof memo);
		int ans = cut(0, n + 1);
		cout << "The minimum cutting is " << ans << "." << endl;
	} 
	return 0;
}
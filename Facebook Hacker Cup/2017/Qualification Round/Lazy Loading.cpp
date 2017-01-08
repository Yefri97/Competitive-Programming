// Greedy
#include <bits/stdc++.h>
using namespace std;

const int MXN = 100;
int arr[MXN + 10];

int main() {
	int t, cs = 1; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		int ans = 0;
		int a = 0, b = n;
		while (a < b) {
			int top = arr[b - 1];
			int x = (50 + top - 1) / top;
			if (x > b - a) break;
			a += x - 1;
			b--;
			ans++;
		}
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
	return 0;
}
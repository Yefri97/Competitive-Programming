#include <bits/stdc++.h>
using namespace std;

int bubble_sort(int v[], int n) {
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int n, v[1010];
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> v[i];
		int ans = bubble_sort(v, n);
		cout << "Minimum exchange operations : " << ans << endl;
	}
	return 0;
}
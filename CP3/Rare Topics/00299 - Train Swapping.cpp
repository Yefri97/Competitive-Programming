#include <bits/stdc++.h>

using namespace std;

int bubble(int v[], int n) {
	int cont = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				cont++;
			}
		}
	}
	return cont;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, v[60]; cin >> n;
		for (int i = 0; i < n; i++) cin >> v[i];
		int ans = bubble(v, n);
		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}
	return 0;
}
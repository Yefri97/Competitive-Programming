// Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

const int MXN = 14;
int n, cube[(1 << MXN) + 10];

int potency(int id) {
	int target = 0;
	for (int i = 0; i < n; i++)
		target += cube[(id ^ (1 << i))];
	return target;
}

int main() {
	while (cin >> n) {
		int l = (1 << n);
		for (int i = 0; i < l; i++)
			cin >> cube[i];
		int ans = -1;
		for (int i = 0; i < l; i++) 
			for (int j = 0; j < n; j++)
				ans = max(ans, potency(i) + potency(i ^ (1 << j)));
		cout << ans << endl;
	}
	return 0;
}
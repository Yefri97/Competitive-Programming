#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int ans = 1;
		for (int x = 1; x % n; x = (x * 10 + 1) % n) ans++;
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d, e;
	while (cin >> a >> b >> c >> d >> e && a + b + c + d + e) {
		int ans = a * b * c * d * d * e * e;
		cout << ans << endl;
	}	
	return 0;
}
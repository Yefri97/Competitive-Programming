#include <bits/stdc++.h>

using namespace std;

int main() {
	cout << fixed << setprecision(0);
	double n, p;
	while (cin >> n >> p) {
		double ans = pow(p, 1/n);
		cout << ans << endl;
	}
	return 0;
}
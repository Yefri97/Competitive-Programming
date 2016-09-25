#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(3);
	double h, m;
	char c;
	while (cin >> h >> c >> m && (h != 0 || m != 0)) {
		double hAngle = (360.0 / 12.0) * h + ((360.0 / 12.0) / 60.0) * m;
		double mAngle = (360.0 / 60.0) * m;
		double ans = abs(hAngle - mAngle);
		cout << min(ans, 360.0 - ans) << endl;
	}
	return 0;
}
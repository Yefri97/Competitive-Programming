// Medium Problems
#include <bits/stdc++.h>
using namespace std;

int main() {
	double h, u, d, f;
	while (cin >> h >> u >> d >> f && h) {
		double ih = 0, df = u * f / 100.0;
		int ans = 0;
		while (true) {
			ans++;
			ih += u;
			u = max(0.0, u - df);
			if (ih > h) break;
			ih -= d;
			if (ih < 0) break;
		}
		cout << ((ih > h)? "success" : "failure") << " on day " << ans << endl;
	}
	return 0;
}
// 2D Array Manipulation
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, p;
	while (cin >> n >> p && (n || p)) {
		ll r = (sqrt(p) - 1) / 2;
		ll a = 2 * r + 1, b = a * a, c = 2 * r + 2;
		ll g = (p - b) / c;
		ll mid = (n + 1) / 2, x = mid + r, y = mid + r;
		if (g == 0 && (p - b) % c != 0) {
			x -= (p - b) % c - 1;
			y += 1;
		}
		if (g == 1) {
			x -= c - 1;
			y -= (p - b) % c - 1;
		}
		if (g == 2) {
			x -= c - 1 - (p - b) % c;
			y -= c - 1;
		}
		if (g == 3) {
			x += 1;
			y -= c - 1 - (p - b) % c;
		}
		cout << "Line = " << y << ", column = " << x << "." << endl;
	}
	return 0;
}
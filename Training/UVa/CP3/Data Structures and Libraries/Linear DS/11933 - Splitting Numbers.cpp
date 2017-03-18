// Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

int solver(int n, int init) {
	int f = init, target = 0;
	for (int i = 0; i < 32; i++) {
		if (n & (1 << i)) {
			if (f) target |= (1 << i);
			f = 1 - f;
		}
	}
	return target;
}

int main() {
	int n;
	while (cin >> n && n) {
		int a = solver(n, 1);
		int b = solver(n, 0);
		cout << a << " " << b << endl;
	}
	return 0;
}
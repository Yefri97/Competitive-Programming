// Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

const int MXN = 1000000;
bitset<MXN + 10> bs;

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		bs.reset();
		bool conflict = false;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			if (conflict) continue;
			for (int j = a; j < b; j++) {
				if (bs.test(j)) conflict = true;
				bs.set(j);
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			if (conflict) continue;
			for (int k = 0; k * c <= MXN; k++) {
				for (int j = a; j < b && k * c + j <= MXN; j++) {
					if (bs.test(k * c + j)) conflict = true;
					bs.set(k * c + j);
				}
			}
		}
		cout << ((conflict)? "CONFLICT" : "NO CONFLICT") << endl;
	}
	return 0;
}
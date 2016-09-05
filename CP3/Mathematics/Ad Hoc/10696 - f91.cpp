#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		cout << "f91(" << n << ") = ";
		if (n > 100)
			cout << n - 10 << endl;
		else
			cout << 91 << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned int a, b;
	while (cin >> a >> b) {
		unsigned int ans = a ^ b;
		cout << ans << endl; 
	}
	return 0;
}
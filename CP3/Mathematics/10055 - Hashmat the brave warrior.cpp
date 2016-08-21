#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b;
	while (cin >> a >> b) {
		long long ans = labs(b - a);
		cout << ans << endl; 
	}
	return 0;
}
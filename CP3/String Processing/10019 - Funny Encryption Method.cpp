#include <bits/stdc++.h>

using namespace std;

int countSetBits(int n) {
	int ans = 0;
	while (n) { n &= n - 1; ans++; }
	return ans;
}

int countSetBitsHEX(int n) {
	int ans = 0;
	while (n) {
		ans += countSetBits(n % 10);
		n /= 10;
	}
	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a = countSetBits(n);
		int b = countSetBitsHEX(n);
		cout << a << " " << b << endl;
	}
	return 0;
}
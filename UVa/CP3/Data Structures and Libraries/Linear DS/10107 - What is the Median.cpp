#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4;

int main() {
	long long v[MAX_N + 10]; v[0] = -1;
	long long n;
	for (int i = 1; cin >> n; i++) {
		v[i] = n;
		for (int j = i; v[j] < v[j - 1]; j--) {
			long long temp = v[j];
			v[j] = v[j - 1];
			v[j - 1] = temp;
		}
		long long ans = (i % 2)? v[(i + 1) / 2] : (v[i / 2] + v[i / 2 + 1]) / 2;
		cout << ans << endl;
	}
	return 0;
}
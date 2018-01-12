// Math: Number Theory
#include <bits/stdc++.h>
using namespace std;

int main() {
	int mx = -1, n; cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		mx = max(mx, input[i]);
	}
	vector<int> v(mx + 1), sieve(mx + 1, 1);
	for (int i = 0; i < input.size(); i++) v[input[i]]++;
	int ans = 1;
	for (int i = 2; i <= mx; i++) if (sieve[i]) {
		int cont = v[i];
		for (int j = 2 * i; j <= mx; j += i) {
			sieve[j] = 0;
			cont += v[j];
		}
		ans = max(ans, cont);
	}
	cout << ans << endl;
	return 0;
}
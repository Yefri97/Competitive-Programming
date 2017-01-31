#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l; cin >> n >> l;
	string a(l, '0'), b(l, '0');
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x] = '1';
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b[x] = '1';
	}
	b += b;
	bool ans = 0;
	for (int i = 0; i < l; i++)
		ans |= (b.substr(i, l) == a);
	cout << ((ans)? "YES" : "NO") << endl;
	return 0;
}
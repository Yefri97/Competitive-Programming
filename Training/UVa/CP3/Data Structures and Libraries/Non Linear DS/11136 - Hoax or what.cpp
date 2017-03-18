// C++ STL set
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		multiset<int> urn;
		multiset<int>::iterator l, h;
		long long ans = 0;
		while (n--) {
			int k; cin >> k;
			while (k--) {
				int x; cin >> x;
				urn.insert(x);
			}
			l = urn.begin();
			h = urn.end(); h--;
			int a = *l, b = *h;
			urn.erase(l);
			urn.erase(h);
			ans += b - a;
		}
		cout << ans << endl;
	}
	return 0;
}
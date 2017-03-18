// C++ STL set
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		set<int> st;
		int ans = 0;
		while (n--) {
			int x; cin >> x;
			st.insert(x);
		}
		while (m--) {
			int x; cin >> x;
			if (st.count(x)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
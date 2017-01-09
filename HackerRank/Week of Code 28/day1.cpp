// Ad hoc
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c, m; cin >> n >> c >> m;
	bool ans = true;
	while (n--) {
		int x; cin >> x;
		ans &= (x <= c * m);
	}
	cout << ((ans)? "Yes" : "No") << endl;
	return 0;
}
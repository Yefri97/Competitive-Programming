#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		vector<int> v;
		for (int i = 0, f = 1; i < n; i++) {
			int x; cin >> x;
			if (x == 0) continue;
			v.push_back(x);
		}
		if (v.size() == 0) {
			cout << 0;
		} else {
			for (int i = 0; i < v.size(); i++) {
				if (i) cout << " ";
				cout << v[i];
			}
		}
		cout << endl;
	}
	return 0;
}
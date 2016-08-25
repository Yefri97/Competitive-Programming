#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x) v.push_back(x);
		}
		if (v.empty())
			cout << 0;
		else
			for (int i = 0; i < v.size(); i++) {
				if (i) cout << " ";
				cout << v[i];
			}
		cout << endl;
	}
	return 0;
}
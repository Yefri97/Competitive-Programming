// C++ STL map
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> input(n);
		for (int i = 0; i < n; i++)
			cin >> input[i];
		input.push_back(input[0]);
		map<int, int> mp;
		int ans = 0;
		for (int a = 0, b = 0; b < input.size(); b++) {
			int x = input[b];
			if (mp.find(x) != mp.end()) {
				ans = max(ans, b - a);
				int idx = mp[x];
				while (a <= idx) {
					mp.erase(mp.find(input[a]));
					a++;
				}
			}
			mp[x] = b;
		}
		cout << ans << endl;
	}
	return 0;
}
// C++ STL algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
		nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
		int ans = v[v.size() / 2];
		if (v.size() % 2 == 0) {
			nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());
			ans = (ans + v[v.size() / 2 - 1]) / 2;
		}
		cout << ans << endl;
	}
	return 0;
}
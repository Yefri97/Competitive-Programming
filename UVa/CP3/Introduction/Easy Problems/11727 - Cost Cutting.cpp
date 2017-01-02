// Super Easy Problems
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cs = 1; cin >> n;
	while (n--) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		cout << "Case " << cs++ << ": " << v[1] << endl;
	}
	return 0;
}
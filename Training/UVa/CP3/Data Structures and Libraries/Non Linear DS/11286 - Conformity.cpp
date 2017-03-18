// C++ STL map
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	int n; 
	while (cin >> n && n) {
		map<vi, int> mp;
		while (n--) {
			vi v(5);
			for (int i = 0; i < 5; i++)
				cin >> v[i];
			sort(v.begin(), v.end());
			mp[v]++;
		}
		int mst = 0, ans = 0;
		for (map<vi, int>::iterator it = mp.begin(); it != mp.end(); it++)
			mst = max(mst, it->second);
		for (map<vi, int>::iterator it = mp.begin(); it != mp.end(); it++)
			if (it->second == mst) ans += mst;
		cout << ans << endl;
	}
	return 0;
}
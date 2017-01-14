// C++ STL map
#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(4);
	int t; cin >> t; cin.ignore();
	string b; getline(cin, b);
	while (t--) {
		string name;
		map<string, int> mp;
		int total = 0;
		while (getline(cin, name) && name.size()) {
			mp[name]++;
			total++;
		}
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
			cout << it->first << " " << ((double)it->second*100.0)/(double)total << endl;
		if (t) cout << endl;
	}
	return 0;
}
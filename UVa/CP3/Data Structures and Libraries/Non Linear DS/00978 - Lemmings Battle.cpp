// C++ STL set
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int t; cin >> t;
	while (t--) {
		multiset<int, greater<int> > green, blue;
		int n, g, b; cin >> n >> g >> b;
		while (g--) {
			int x; cin >> x;
			green.insert(x);
		}
		while (b--) {
			int x; cin >> x;
			blue.insert(x);
		}
		multiset<int, greater<int> >::iterator itg, itb;
		while (!green.empty() && !blue.empty()) {
			vector<ii> field;
			for (int i = 0; i < n; i++) {
				if (green.empty() || blue.empty()) break;
				itg = green.begin();
				itb = blue.begin();
				int a = *itg, b = *itb;
				field.push_back(ii(a, b));
				green.erase(itg);
				blue.erase(itb);
			}
			for (int i = 0; i < field.size(); i++) {
				int a = field[i].first, b = field[i].second;
				if (a > b) green.insert(a - b);
				if (a < b) blue.insert(b - a);
			}
		}
		if (green.empty() && blue.empty()) {
			cout << "green and blue died" << endl;
		} else if (blue.empty()) {
			cout << "green wins" << endl;
			for (itg = green.begin(); itg != green.end(); itg++)
				cout << *itg << endl;
		}	else {
			cout << "blue wins" << endl;
			for (itb = blue.begin(); itb != blue.end(); itb++)
				cout << *itb << endl;
		}
		if (t) cout << endl;
	}	
	return 0;
}
// Medium Problems
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p, cs = 0;
	while (cin >> n >> p && (n || p)) {
		int mmax = -1;
		double prmin;
		string ans;
		cin.ignore();
		while (n--) {
			string x; getline(cin, x);
		}
		while (p--) {
			string name; getline(cin, name);
			double price; cin >> price;
			int m; cin >> m;
			if (m > mmax || (m == mmax && price < prmin)) {
				mmax = m;
				prmin = price;
				ans = name;
			}
			cin.ignore();
			while (m--) {
				string x; getline(cin, x);
			}
		}
		if (cs) cout << endl;
		cout << "RFP #" << ++cs << endl;
		cout << ans << endl;
	}
	return 0;
}
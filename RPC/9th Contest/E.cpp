/*
 *  RPC 9-th Contest 2016
 *  Problem E: Wheel of Universally Copious Fortune
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<string> vs(n);
	for (int i = 0; i < n; i++) cin >> vs[i];
	int q, cs = 0; cin >> q;
	while (q--) {
		string s; cin >> s;
		cout << "Word #" << ++cs << ": " << s << endl;
		int cont = 0;
		for (int i = 0; i < n; i++) {
			string temp = vs[i];
			if (temp.size() != s.size()) continue;
			int ok = 1;
			for (int j = 0; j < temp.size(); j++) {
				if (s[j] == '-') continue;
				if (temp[j] != s[j]) ok = 0;
			}
			if (ok) {
				cout << temp << endl;
				cont++;
			}
		}
		cout << "Total number of candidate words = " << cont << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while (cin >> s) {
		set<string> ss;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i; j < s.size(); j++) {
				string subs = s.substr(i, j - i + 1);
				ss.insert(subs);
			}
		}
		int ans = 0;
		for (set<string>::iterator it = ss.begin(); it != ss.end(); it++) {
			string a, b;
			a = b = *it;
			reverse(b.begin(), b.end());
			if (a == b) ans++;
		}
		cout << "The string '" << s << "' contains " << ans << " palindromes." << endl;
	}	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int next_int() {
	string line; getline(cin, line);
	return atoi(line.c_str());
}

int main() {
	int n = next_int();
	vector< pair<int, int> > vp(26);
	for (int i = 0; i < vp.size(); i++) vp[i].second = -(i + 'A');
	while (n--) {
		string line; getline(cin, line);
		for (int i = 0; i < line.size(); i++) {
			if (!isalpha(line[i])) continue;
			int c = toupper(line[i]) - 'A';
			vp[c].first++;
		}
	}
	sort(vp.rbegin(), vp.rend());
	for (int i = 0; i < vp.size(); i++) if (vp[i].first)
		cout << char(-vp[i].second) << " " << vp[i].first << endl;
	return 0;
}
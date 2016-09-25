#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
	vector<string> v;
	istringstream iss(s);
	while (iss >> s) v.push_back(s);
	return v;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<string> vs = split(line);
		for (int i = 0; i < vs.size(); i++) reverse(vs[i].begin(), vs[i].end());
		for (int i = 0; i < vs.size(); i++) {
			if (i) cout << " ";
			cout << vs[i];
		}
		cout << endl;
	}
	return 0;
}
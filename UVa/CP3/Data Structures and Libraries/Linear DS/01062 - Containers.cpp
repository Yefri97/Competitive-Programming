// C++ STL stack
#include <bits/stdc++.h>
using namespace std;

int main() {
	int cs = 1;
	string line;
	while (cin >> line && line != "end") {
		vector<char> vc;
		for (int i = 0; i < line.size(); i++) {
			char c = line[i];
			int id = 0;
			while (id < vc.size() && c > vc[id]) id++;
			if (id == vc.size()) {
				vc.push_back(c);
			} else {
				vc[id] = c;
			}
		}
		for (int i = 0; i < vc.size(); i++) cout << vc[i]; cout << endl;
		cout << "Case " << cs++ << ": " << vc.size() << endl;
	}
	return 0;
}
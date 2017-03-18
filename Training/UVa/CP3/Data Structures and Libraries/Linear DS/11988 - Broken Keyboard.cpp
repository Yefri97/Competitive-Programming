// C++ STL list
#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	while (cin >> line) {
		line.push_back(']');
		list<string> l;
		string s;
		char key = '[';
		for (int i = 0; i < line.size(); i++) {
			char c = line[i];
			if (c == '[' || c == ']') {
				if (key == '[') l.push_front(s);
				if (key == ']') l.push_back(s);
				key = c;
				s.clear();
			} else {
				s.push_back(c);
			}
		}
		while (!l.empty()) {
			cout << l.front();
			l.pop_front();
		}
		cout << endl;
	}
	return 0;
}
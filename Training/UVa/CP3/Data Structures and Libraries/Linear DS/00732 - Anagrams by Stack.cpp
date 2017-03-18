// C++ STL stack
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<string> vs;
string source, target, ans;
stack<char> s;

void solver(int id, int it, int ik) {
	if (id == ans.size()) vs.push_back(ans);
	if (it < n) {
		ans[id] = 'i';
		s.push(source[it]);
		solver(id + 1, it + 1, ik);
		s.pop();
	}
	if (ik < it) {
		char c = s.top();
		if (c != target[ik]) return;
		ans[id] = 'o';
		s.pop();
		solver(id + 1, it, ik + 1);
		s.push(c);
	}
}

int main() {
	while (cin >> source) {
		cin >> target;
		vs.clear();
		n = source.size();
		ans.resize(2 * n);
		if (source.size() == target.size()) solver(0, 0, 0);
		cout << "[" << endl;
		for (int i = 0; i < vs.size(); i++) {
			for (int j = 0; j < vs[i].size(); j++) {
				if (j) cout << " ";
				cout << vs[i][j];
			}
			cout << endl;
		}
		cout << "]" << endl;
	}
	return 0;
}
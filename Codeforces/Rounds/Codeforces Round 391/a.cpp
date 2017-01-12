#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
string name = "Bulbasaur";

bool check(char c) { 
	for (int i = 0; i < name.size(); i++)
		if (name[i] == c) return true;
	return false;
}

int main() {
	string line; cin >> line;
	map<char, int> m;
	for (int i = 0; i < name.size(); i++) m[name[i]] = 0;
	for (int i = 0; i < line.size(); i++) {
		char c = line[i];
		if (check(c)) m[c]++;
	}
	m[name[1]] /= 2;
	m[name[4]] /= 2;
	int ans = INF;
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		ans = min(ans, it->second);
	cout << ans << endl;
	return 0;
}
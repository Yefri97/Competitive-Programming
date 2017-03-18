#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
	vector<string> v;
	istringstream iss(s);
	while (iss >> s) v.push_back(s);
	return v;
}

int next_int() {
	string line; getline(cin, line);
	return atoi(line.c_str());
}

int main() {
	map<string, int> mm;
	int n = next_int();
	while (n--) {
		string line; getline(cin, line);
		vector<string> vs = split(line);
		mm[vs[0]]++;
	}
	for (map<string, int>::iterator it = mm.begin(); it != mm.end(); it++) 
		cout << it -> first << " " << it -> second << endl;
	return 0;
}
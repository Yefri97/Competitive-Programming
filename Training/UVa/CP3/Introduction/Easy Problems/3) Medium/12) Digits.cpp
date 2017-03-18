#include <bits/stdc++.h>
using namespace std;

string number_to_string(int n) {
	ostringstream convert;
	convert << n;
	return convert.str();
}

int solver(string s) {
	if (s == "1") return 1;
	string size = number_to_string(s.size());
	return solver(size) + 1;
}

int main() {
	string line;
	while (cin>>line && line != "END") {
		int target = solver(line);
		cout<<target<<endl;
	}
	return 0;
}
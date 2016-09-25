#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	for (int t = 0; t < T; ++t) {
		vector<int> v(110);
		string line; cin>>line;
		for (int i_string = 0, i_memory = 0; i_string < line.size(); ++i_string) {
			if (line[i_string] == '<') {
				i_memory = (i_memory == 0)? 99 : i_memory - 1;
			} else if (line[i_string] == '>') {
				i_memory = (i_memory == 99)? 0 : i_memory + 1;
			} else if (line[i_string] == '-') {
				v[i_memory] = (v[i_memory] == 0)? 255 : v[i_memory] - 1;
			} else if (line[i_string] == '+') {
				v[i_memory] = (v[i_memory] == 255)? 0 : v[i_memory] + 1;
			}
		}
		cout<<"Case "<<t+1<<":";
		for (int i = 0; i < 100; ++i) {
			printf(" %02X", v[i]);
		}
		cout<<endl;
	}
	return 0;
}
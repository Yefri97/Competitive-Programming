#include <bits/stdc++.h>
using namespace std;

int get_int() {
	string line;
	getline(cin, line);
	return atoi(line.c_str());
}

int main(int argc, char const *argv[])
{
	int N = get_int();
	while (N--) {
		string line, target = "NO LOOP";
		getline(cin, line);
		if (line.size() > 2) {
			int female = 0, male = 0;
			for (int i = 0; i < line.size(); i++) {
				if ((i+1)%3) {
					if (line[i] == 'F') {
						female++;
					} else {
						male++;
					}
				}
			}
			if (female == male) target = "LOOP";
		}
		cout<<target<<endl;
	}
	return 0;
}
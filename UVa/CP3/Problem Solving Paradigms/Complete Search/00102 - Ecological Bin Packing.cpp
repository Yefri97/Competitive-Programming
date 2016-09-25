#include <bits/stdc++.h>
using namespace std;

map<char, int> mm = {{'B', 0}, {'G', 1}, {'C', 2}};
vector<string> vs = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main() {
	int num[5][5];
	while (cin >> num[0][0]) {
		for (int i = 0; i < 3; i++) 
			for (int j = ((i)? 0 : 1); j < 3; j++)
				cin >> num[i][j];
		int total = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				total += num[i][j];
		string ans;
		int mmax = -1;
		for (int i = 0; i < 6; i++) {
			int acc = 0;
			for (int j = 0; j < 3; j++) acc += num[j][mm[vs[i][j]]];
			if (acc > mmax) {
				mmax = acc;
				ans = vs[i];
			}
		}
		cout << ans << " " << total - mmax << endl;
	}
	return 0;
}
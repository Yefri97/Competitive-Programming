// 1D Array Manipulation
#include <bits/stdc++.h>
using namespace std;

int price[300];

int main() {
	int t; cin >> t;
	while (t--) {
		memset(price, 0, sizeof price);
		int n; cin >> n;
		while (n--) {
			unsigned char c; cin >> c;
			int x; cin >> x;
			price[(int)c] = x;
		}
		cin >> n;
		cin.ignore();
		int total = 0;
		while (n--) {
			string line; getline(cin, line);
			for (int i = 0; i < line.size(); i++) {
				unsigned char c = line[i];
				total += price[(int)c];
			}
		}
		double ans = (double)total/100.0;
		cout << fixed << setprecision(2) << ans << "$" << endl; 
	}
	return 0;
}
// Medium Problems
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		n--;
		string ans = "+x";
		while (n--) {
			string in; cin >> in;
			if (in == "+y") {
				if (ans == "+x") ans = "+y";
				else if (ans == "-x") ans = "-y";
				else if (ans == "+y") ans = "-x";
				else if (ans == "-y") ans = "+x";
			} else if (in == "-y") {
				if (ans == "+x") ans = "-y";
				else if (ans == "-x") ans = "+y";
				else if (ans == "+y") ans = "+x";
				else if (ans == "-y") ans = "-x";
			} else if (in == "+z") {
				if (ans == "+x") ans = "+z";
				else if (ans == "-x") ans = "-z";
				else if (ans == "+z") ans = "-x";
				else if (ans == "-z") ans = "+x";
			} else if (in == "-z") {
				if (ans == "+x") ans = "-z";
				else if (ans == "-x") ans = "+z";
				else if (ans == "+z") ans = "+x";
				else if (ans == "-z") ans = "-x";
			}
		}
		cout << ans << endl;
	}
	return 0;
}
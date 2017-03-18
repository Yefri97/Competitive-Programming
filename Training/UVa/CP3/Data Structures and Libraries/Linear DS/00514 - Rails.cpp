// C++ STL stack
#include <bits/stdc++.h>
using namespace std;

const int MXN = 1000;
int target[MXN + 10];

int main() {
	int n;
	while (cin >> n && n) {
		while (cin >> target[0] && target[0]) {
			bool ans = true;
			stack<int> s; s.push(-1);
			for (int i = 1; i < n; i++)
				cin >> target[i];
			int c = 1;
			for (int i = 0; i < n && ans; i++) {
				while (s.top() != target[i] && c <= n) {
					s.push(c);
					c++;
				}
				if (s.top() == target[i]) s.pop();
				else ans = false;
			}
			cout << ((ans)? "Yes" : "No") << endl;
		}
		cout << endl;
	}
	return 0;
}
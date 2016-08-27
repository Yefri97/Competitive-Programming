#include <bits/stdc++.h>

using namespace std;

int solver(int n) {
	int acc = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0) acc += i;
	return (n == acc)? 0 : (acc < n)? 1 : 2;
}

int main() {
	vector<string> vs = {"PERFECT", "DEFICIENT", "ABUNDANT"};
	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> n && n) {
		cout << setw(5) << n << "  ";
		int ans = solver(n);
		cout << vs[ans] << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
// Easy Problems
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
double arr[MAXN + 10];

int main() {
	int m, n;
	double ini, loan;
	while (cin >> m >> ini >> loan >> n && m > 0) {
		while (n--) {
			int a; cin >> a;
			double b; cin >> b;
			for (int i = a; i < 101; i++) arr[i] = b;
		}
		int ans = 0;
		double k = loan / m, own = loan, vc = (loan + ini) * (1 - arr[0]);
		while (vc < own) {
			ans++;
			vc = vc * (1 - arr[ans]);
			own -= k;
		}
		cout << ans << " month";
		if (ans != 1) cout << "s";
		cout << endl;
	}
	return 0;
}
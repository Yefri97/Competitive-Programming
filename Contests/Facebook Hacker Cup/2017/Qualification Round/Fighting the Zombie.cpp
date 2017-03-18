// Math Probability + DP
#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 20, MAX_Z = 10000;
double memo[MAX_X + 10][2 * MAX_Z + 10];
int target, num_face;

double solver(int val, int k) {
	if (target <= val) return 1.0;
	if (k == 0) return 0.0;
	if (memo[k][val + MAX_Z] != -1) return memo[k][val + MAX_Z];
	double p = 0.0;
	for (int i = 0; i < num_face; i++)
		p += (1.0 / (double)num_face) * solver(val + i + 1, k - 1);
	return memo[k][val + MAX_Z] = p;
}

int to_int(string s) { return atoi(s.c_str()); }

int main() {
	cout << fixed << setprecision(6);
	int t, cs = 1; cin >> t;
	while (t--) {
		int h, n; cin >> h >> n;
		target = h;
		double ans = -1.0;
		while (n--) {
			string in; cin >> in;
			int a = 0, b = 0;
			while (in[a] != 'd') a++;
			while (b < in.size() && in[b] != '+' && in[b] != '-') b++;
			int x = to_int(in.substr(0, a));
			int y = to_int(in.substr(a + 1, b - a - 1));
			int z = 0;
			if (b < in.size())
				z = ((in[b] == '-')? -1 : 1) * to_int(in.substr(b + 1, in.size() - b - 1));
			num_face = y;
			for (int i = 0; i <= x; i++)
				for (int j = z; j <= h; j++)
					memo[i][j + MAX_Z] = -1.0;
			double p = solver(z, x);
			ans = max(ans, p);
		}
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
	return 0;
}
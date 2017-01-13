#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
int n;
ll memo[200000+2][2+2][4+2][5+2];
string num;

ll solver(int id, int a, int b, int c, int it) {
	if (it == 3) return ((100 * a + 10 * b + 2 * c) % 8 == 0);
	if (id == n) return 0;
	if (memo[id][a + 1][b + 1][c + 1] != -1) return memo[id][a + 1][b + 1][c + 1];
	int x = num[id] - '0';
	ll ans = solver(id + 1, a, b, c, it);
	if (it == 0) ans += solver(id + 1, x%2, b, c, it + 1);
	if (it == 1) ans += solver(id + 1, a, x%4, c, it + 1);
	if (it == 2 && x%2 == 0) ans += solver(id + 1, a, b, x/2, it + 1);
	return memo[id][a + 1][b + 1][c + 1] = ans % MOD;
}

int main() {
	cin >> n >> num;
	memset(memo, -1, sizeof memo);
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		v[i] = solver(i + 1, (num[i] - '0')%2, -1, -1, 1);
	ll ans = (solver(0, 0, -1, -1, 1) + solver(0, 0, 0, -1, 2))%MOD, pt = 1;
	for (int i = 0; i < n; i++) {
		ans = (ans + v[i] * pt)%MOD;
		pt = (pt * 2)%MOD;
	}
	cout << ans << endl;
	return 0;
}
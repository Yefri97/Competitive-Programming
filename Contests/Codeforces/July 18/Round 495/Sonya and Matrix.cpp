#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1000010;

int f[MN], freq[MN];

int can(int n, int m, int x, int y) {
	if (n < x || m < y) return 0;
	memset(f, 0, sizeof f);
	fori(i, 1, n + 1)
		fori(j, 1, m + 1)
			f[abs(i - x) + abs(j - y)]++;
	fori(i, 0, n * m)
		if (f[i] != freq[i])
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	int b = 0;
	fori(i, 0, t) {
		int c; cin >> c;
		freq[c]++;
		b = max(b, c);
	}
	int x = 1;
	while (freq[x] == 4 * x)
		x++;
	int n, m, y, ok = 0;
	for (int i = 1; i * i <= t; i++) if (t % i == 0) {
		n = i, m = t / i, y = n + m - b - x;
		if (can(n, m, x, y)) ok = 1;
		if (ok) break;
		swap(n, m);
		if (can(n, m, x, y)) ok = 1;
		if (ok) break;
	}
	if (ok) {
		cout << n << " " << m << endl;
		cout << x << " " << y << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}

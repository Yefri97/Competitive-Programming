#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< vector<ll> > vvll;

const int oo = 1e9, MD = 1e9 + 7;

void mult(vvll a, vvll b, vvll &ans) {
	assert(a[0].size() == b.size());
	fori(i, 0, a.size()) {
		fori(j, 0, b[0].size()) {
			ans[i][j] = 0;
			fori(k, 0, b.size())
				ans[i][j] = (ans[i][j] + ((a[i][k] * b[k][j]) % MD)) % MD;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	int k, x; cin >> k >> x;
	vvll t(n, vector<ll>(m));
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> t[i][j];
	int len = n * m;
	vvll ans(len, vector<ll>(len));
	fori(i, 0, len) fori(j, 0, len) ans[i][j] = (i == j);
	vvll b(len, vector<ll>(len));
	fori(p, 0, len) fori(q, 0, len) {
		int i1 = p / m, j1 = p % m;
		int i2 = q / m, j2 = q % m;
		if (i1 == i2 && j1 == j2) {
			int cnt = 0;
			cnt += (i1 > 0);
			cnt += (j1 > 0);
			cnt += (i1 < n - 1);
			cnt += (j1 < m - 1);
			b[p][q] = (1 - k * cnt + MD) % MD;
		}
		if (abs(i1 - i2) + abs(j1 - j2) == 1) {
			b[p][q] = k;
		}
	}
	int e = x;
	while (e) {
		if (e & 1)
			mult(ans, b, ans);
		mult(b, b, b);
		e >>= 1;
	}
	fori(i, 0, n) {
		fori(j, 0, m) {
			int c = 0;
			fori(l, 0, len)
				c = (c + ans[i * m + j][l] * t[l / m][l % m]) % MD;
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}

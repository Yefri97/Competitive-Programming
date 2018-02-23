/*
ID: yefri97
PROG: retal
LANG: C++11
*/
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ifstream fin("retal.in");
	ofstream fout("retal.out");

	int n, m, r; fin >> n >> m >> r;

	vi c(n);
	fori(i, 0, n)
		fin >> c[i];
	sort(c.rbegin(), c.rend());

	priority_queue<ii> pq;
	fori(i, 0, m) {
		int q, p; fin >> q >> p;
		pq.push(ii(p, q));
	}

	vi v(r);
	fori(i, 0, r)
		fin >> v[i];
	sort(v.rbegin(), v.rend());
	fori(i, 1, r)
		v[i] += v[i - 1];

	int ans = 0;
	for (int i = 0, f = 0, g = 0; i <= n; i++) {
		int a = (i == 0) ? 0 : c[i - 1], b = n - i;

		f = b < r ? (b == 0 ? 0 : v[b - 1]) : v[r - 1];

		while (!pq.empty() && a > 0) {
			ii top = pq.top(); pq.pop();
			int p = top.first, q = top.second;
			int mm = min(a, q);
			q -= mm;
			a -= mm;
			g += p * mm;
			if (q > 0)
				pq.push(ii(p, q));
		}

		ans = max(ans, f + g);
	}

	fout << ans << endl;

	return 0;
}
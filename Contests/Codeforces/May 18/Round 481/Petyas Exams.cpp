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
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vi> v(n);
	vi d(m), k(m);
	fori(i, 0, m) {
		int l, r; cin >> l >> r >> k[i];
		v[l - 1].push_back(i);
		d[i] = r - l;
	}
	vi days(n), curr(m);
	int ok = 1;
	fori(i, 0, n) {
		for (int x : v[i])
			curr[x] = 1;
		int exam = -1;
		fori(id, 0, m) if (curr[id])
			if (d[id] == 0)
				exam = id;
		if (exam == -1) {
			int best = -1;
			fori(id, 0, m) if (curr[id]) {
				if (k[id] == 0) continue;
				if (best == -1 || d[id] - k[id] < d[best] - k[best])
					best = id;
			}
			if (best != -1) {
				if (d[best] - k[best] < 0) { ok = 0; break; }
				days[i] = best + 1;
				k[best]--;
			} else {
				days[i] = 0;
			}
		} else {
			if (k[exam] > 0) { ok = 0; break; }
			days[i] = m + 1;
			curr[exam] = 0;
		}
		fori(id, 0, m) if (curr[id])
			d[id]--;
	}
	if (ok) {
		fori(i, 0, n)
			cout << days[i] << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}

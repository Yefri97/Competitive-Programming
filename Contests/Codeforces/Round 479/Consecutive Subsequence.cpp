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
	map<int, vi> m;
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n) {
		cin >> v[i];
		m[v[i]].push_back(i);
	}
	vi k(n, 1), nxt(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		vi &t = m[v[i] + 1];
		int p = upper_bound(t.begin(), t.end(), i) - t.begin();
		if (p == t.size()) continue;
		int idx = t[p];
		k[i] = k[idx] + 1;
		nxt[i] = idx;
	}
	int p = max_element(k.begin(), k.end()) - k.begin();
	cout << k[p] << endl;
	cout << p + 1;
	while (nxt[p] != -1) {
		p = nxt[p];
		cout << " " << p + 1;
	}
	cout << endl;
	return 0;
}

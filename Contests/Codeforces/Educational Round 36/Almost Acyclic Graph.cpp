#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, MX = 500;

int n, m;
int state[MX];
ii edge_erase;
vi g[MX];
vii cycle;

bool check(int u) {
	if (state[u] == 0)
		return true;
	if (state[u] == 1)
		return false;
	state[u] = 0;
	for (int v : g[u]) {
		if (ii(u, v) == edge_erase) continue;
		if (check(v))
			return true;
	}
	state[u] = 1;
	return false;
}

bool find_cycle(int u) {
	if (state[u] == 0)
		return true;
	if (state[u] == 1)
		return false;
	state[u] = 0;
	for (auto v : g[u]) {
		cycle.push_back(ii(u, v));
		if (find_cycle(v))
			return true;
		cycle.pop_back();
	}
	state[u] = 1;
	return false;
}

int solver() {
	bool ans = 0, ok = 1;

	memset(state, -1, sizeof state);
	fori(i, 0, n)
		if (find_cycle(i))
			ok = 0;

	if (ok)
		return 1;

	for (auto e : cycle) {
		edge_erase = e;
		ok = 0;
		memset(state, -1, sizeof state);
		fori(i, 0, n)
			ok |= check(i);
		if (!ok)
			return 1;
	}

	return 0;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	fori(i, 0, m) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
	}

	int ans = solver();

	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 30;

int seen[MN];
vi g[MN], ans;

void dfs(int u) {
	seen[u] = 1;
	for (int v : g[u])
		if (seen[v] == -1)
			dfs(v);
	ans.push_back(u);
}

int check(int u) {
	seen[u] = 0;
	for (int v : g[u]) {
		if (seen[v] == 0) return 1;
		if (seen[v] == 1) continue;
		if (check(v)) return 1;
	}
	seen[u] = 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	fori(i, 0, n)
		cin >> v[i];
	int cycle = 0;
	fori(i, 0, n) {
		fori(j, 0, i) {
			string a = v[i], b = v[j];
			int c = 0;
			while (c < a.size() && c < b.size() && a[c] == b[c]) c++;
			if (c < a.size() && c < b.size())
				g[a[c] - 'a'].push_back(b[c] - 'a');
			else
				cycle |= (b.size() > a.size());
		}
	}
	memset(seen, -1, sizeof seen);
	fori(i, 0, 26) {
		if (seen[i] == -1)
			cycle |= check(i);
	}
	if (cycle) { cout << "Impossible" << endl; return 0; }
	memset(seen, -1, sizeof seen);
	fori(i, 0, 26) {
		if (seen[i] == -1)
			dfs(i);
	}
	for (int c : ans)
		cout << (char)(c + 'a');
	cout << endl;
	return 0;
}

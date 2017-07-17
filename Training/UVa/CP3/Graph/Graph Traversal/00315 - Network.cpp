#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 110;

int dfsNumberCounter, dfsRoot, rootChildren;
vi g[mxn], dfs_num, dfs_low, dfs_parent, articulation_vertex;

void articulationPoint(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	fori(j, 0, g[u].size()) {
		int v = g[u][j];
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;

			articulationPoint(v);

			if (dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int nextInt() {
	string n; getline(cin, n);
	return atoi(n.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while ((n = nextInt()) && n) {
		fori(i, 0, n) g[i].clear();
		string line;
		while (getline(cin, line) && line[0] != '0') {
			vector<string> vs = splitLine(line);
			int x = atoi(vs[0].c_str()); x--;
			fori(i, 1, vs.size()) {
				int y = atoi(vs[i].c_str()); y--;
				g[x].push_back(y);
				g[y].push_back(x);
			}
		}
		// articulationPoint
		dfsNumberCounter = 0; dfs_num.assign(n, -1); dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0); articulation_vertex.assign(n, 0);
		fori(i, 0, n) {
			if (dfs_num[i] == -1) {
				dfsRoot = i; rootChildren = 0;
				articulationPoint(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		int ans = accumulate(articulation_vertex.begin(), articulation_vertex.end(), 0);
		cout << ans << endl;
	}
	return 0;
}
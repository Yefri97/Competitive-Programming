/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Harry Potter and the Railroad
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 50001, MAXM = 150000;

vector<int> g[MAXN];
int from[MAXM], to[MAXM];
int label[MAXM];
bool was[MAXN];
int curr = 1;

void dfs(int u) {
	was[u] = true;
	fori(i,0,g[u].size()) {
		int e = g[u][i];
		if (label[e] == 0) {
			label[e] = curr++;
			int v = (from[e] + to[e]) - u;
			if (!was[v])
				dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);  // Fast input - output
	ifstream fin("input.txt");    // File Input
	ofstream fout("output.txt");  // File Output
	/*** Code ***/
	int n, m; fin >> n >> m;
	fori(i,0,m) {
		int a, b; fin >> a >> b; a--; b--;
		from[i] = a;
		to[i] = b;
		g[a].push_back(i);
		g[b].push_back(i);
	}

	int start = -1;
	fori(u,0,n) {
		if (g[u].size() == 1) {
			if (start == -1) {
				start = u;
			} else {
				fout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}

	if (start == -1)
		start = 0;

	dfs(start);

	fori(i,0,m)
		fout << label[i] << endl;

	return 0;
}
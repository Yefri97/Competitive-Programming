/*
ID: yefri.g1
PROG: milk3
LANG: C++11
*/
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

set<int> ans;
int total[5];
int vis[30][30][30];

vi process(int a, int b, vi curr) {
	int k = min(total[a] - curr[a], curr[b]);
	vi v = curr;
	v[a] += k;
	v[b] -= k;
	return v;
}

void dfs(vi u) {
	vis[u[0]][u[1]][u[2]] = 1;
	if (u[0] == 0) ans.insert(u[2]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vi v = process(i, j, u);
			if (!vis[v[0]][v[1]][v[2]])
				dfs(v);
		}
	}
}

int main() {
  ifstream fin ("milk3.in");
  ofstream fout ("milk3.out");
	for (int i = 0; i < 3; i++)
		fin >> total[i];
	dfs({0, 0, total[2]});
	bool first = 1;
	for (int x : ans) {
		if (!first) fout << " "; first = 0;
		fout << x;
	}
	fout << endl;
	return 0;
}
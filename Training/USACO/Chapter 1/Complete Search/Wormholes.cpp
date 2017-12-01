/*
ID: yefri.g1
PROG: wormhole
LANG: C++
*/
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

const int oo = 1e9;

vi nxt;

bool check(vi &matches) {
	int n = matches.size();
	fori(u, 0, n) {
		int curr = u;
		vi visited(n);
		visited[curr] = 1;
		while (nxt[matches[curr]] != -1 && visited[nxt[matches[curr]]] == 0) {
			curr = nxt[matches[curr]];
			visited[curr] = 1;
		}
		if (nxt[matches[curr]] != -1) return true;
	}
	return false;
}

int backtracking(vi &matches) {
	int u = -1;
	fori(i, 0, matches.size())
		if (matches[i] == -1)
			u = i;
	if (u == -1) return check(matches);
	int ans = 0;
	fori(i, 0, u) {
		if (matches[i] == -1) {
			matches[i] = u;
			matches[u] = i;
			ans += backtracking(matches);
			matches[i] = -1;
			matches[u] = -1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin ("wormhole.in");
	ofstream fout ("wormhole.out");
	int n; fin >> n;
	vii points(n);
	fori(i, 0, n)
		fin >> points[i].first >> points[i].second;
	nxt.assign(n, -1);
	fori(i, 0, n)
		fori(j, 0, n)
			if (points[j].second == points[i].second && 
					points[j].first > points[i].first && 
					(nxt[i] == -1 || points[j].first < points[nxt[i]].first))
				nxt[i] = j;
	vi matches(n, -1);
	int ans = backtracking(matches);
	fout << ans << endl;
	return 0;
}
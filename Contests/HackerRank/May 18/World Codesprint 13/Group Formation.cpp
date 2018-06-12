#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

struct UnionFind {
	vi p, size, cntf, cnts, cntt;
	UnionFind(int n) : p(n, -1), size(n, 1), cntf(n), cnts(n), cntt(n) {}
	int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
	void unionSet(int i, int j) {
		int a = findSet(j), b = findSet(i);
		if (a != b) { p[a] = b; size[b] += size[a]; cntf[b] += cntf[a]; cnts[b] += cnts[a]; cntt[b] += cntt[a]; }
	}
	int sizeSet(int i) { return size[findSet(i)]; }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, a, b, f, s, t; cin >> n >> m >> a >> b >> f >> s >> t;
	UnionFind dsu(n);
	vi grades(n);
	vector<string> names(n);
	map<string, int> mapper;
	fori(i, 0, n) {
		cin >> names[i] >> grades[i];
		mapper[names[i]] = i;
		if (grades[i] == 1) dsu.cntf[i]++;
		if (grades[i] == 2) dsu.cnts[i]++;
		if (grades[i] == 3) dsu.cntt[i]++;
	}
	fori(i, 0, m) {
		string name0, name1; cin >> name0 >> name1;
		int x = mapper[name0], y = mapper[name1];
		int set0 = dsu.findSet(x), set1 = dsu.findSet(y);
		if (set0 == set1) continue;
		if (dsu.sizeSet(set0) + dsu.sizeSet(set1) > b) continue;
		if (dsu.cntf[set0] + dsu.cntf[set1] > f) continue;
		if (dsu.cnts[set0] + dsu.cnts[set1] > s) continue;
		if (dsu.cntt[set0] + dsu.cntt[set1] > t) continue;
		dsu.unionSet(set0, set1);
	}
	int mmax = *max_element(dsu.size.begin(), dsu.size.end());
	if (mmax < a) {
		cout << "no groups" << endl;
	} else {
		vector<string> ans;
		fori(i, 0, n)
			if (dsu.sizeSet(i) == mmax)
				ans.push_back(names[i]);
		sort(ans.begin(), ans.end());
		for (string x : ans)
			cout << x << endl;
	}
	return 0;
}

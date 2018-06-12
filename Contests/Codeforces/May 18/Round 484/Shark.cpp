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
	int num;
	vi p, size;
	UnionFind(int n) : p(n, -1), size(n, 1), num(n) {}
	int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
	void unionSet(int i, int j) {
		int a = findSet(j), b = findSet(i);
		if (a != b) { p[a] = b; size[b] += size[a]; num--; }
	}
	int numSets() { return num; }
	int sizeSet(int i) { return size[findSet(i)]; }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	vector<ii> w(n);
	fori(i, 0, n)
		w[i] = ii(v[i], i);
	sort(w.begin(), w.end());
	UnionFind dsu(n);
	map<int, int> cnt;
	int k = 0, c = 0;
	fori(i, 0, n) {
		int val = w[i].first;
		int id = w[i].second;
		if (id > 0 && v[id - 1] < val) {
			cnt[dsu.sizeSet(id - 1)]--;
			if (cnt[dsu.sizeSet(id - 1)] == 0)
				cnt.erase(dsu.sizeSet(id - 1));
			dsu.unionSet(id - 1, id);
		}
		if (id < n - 1 && v[id + 1] < val) {
			cnt[dsu.sizeSet(id + 1)]--;
			if (cnt[dsu.sizeSet(id + 1)] == 0)
				cnt.erase(dsu.sizeSet(id + 1));
			dsu.unionSet(id + 1, id);
		}
		cnt[dsu.sizeSet(id)]++;
		if (cnt.size() == 1 && dsu.numSets() - (n - i - 1) > c) {
			c = dsu.numSets() - (n - i - 1);
			k = val;
		}
	}
	cout << k + 1 << endl;
	return 0;
}

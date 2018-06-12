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
	int n; cin >> n;
	vector<vi> v(n);
	vi sum(n);
	fori(i, 0, n) {
		int k; cin >> k;
		fori(j, 0, k) {
			int x; cin >> x;
			v[i].push_back(x);
		}
		sum[i] = accumulate(v[i].begin(), v[i].end(), 0);
	}
	map< int, vector<ii> > mapper;
	fori(i, 0, n) {
		set<int> dict;
		fori(j, 0, v[i].size()) {
			if (dict.count(v[i][j]) > 0) continue;
			mapper[sum[i] - v[i][j]].push_back(ii(i, j));
			dict.insert(v[i][j]);
		}
	}
	for (auto x : mapper) {
		if (x.second.size() < 2) continue;
		cout << "YES" << endl;
		cout << x.second[0].first + 1 << " " << x.second[0].second + 1 << endl;
		cout << x.second[1].first + 1 << " " << x.second[1].second + 1 << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}

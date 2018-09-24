#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

vi a[MN], dp[MN];

void show(int id) {
	cout << (id == -1 ? "impossible" : id == 0 ? "unique" : "ambiguous") << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector< pair<int, string> > input(m);
	fori(i, 0, m)
		cin >> input[i].first >> input[i].second;
	map<string, int> mapper;
	int k; cin >> k;
	fori(i, 0, k) {
		string name; cin >> name;
		mapper[name] = i;
	}
	fori(i, 0, m) if (mapper.count(input[i].second))
		a[mapper[input[i].second]].push_back(input[i].first);
	fori(i, 0, k) {
		sort(a[i].begin(), a[i].end());
		dp[i] = vi(SZ(a[i]), (i == k - 1));
	}
	for (int i = k - 2; i >= 0; i--) {
		for (int j = 0; j < SZ(a[i]); j++) {
			int p = lower_bound(a[i + 1].begin(), a[i + 1].end(), a[i][j]) - a[i + 1].begin();
			if (p < SZ(a[i + 1]))
				dp[i][j] = dp[i + 1][p];
		}
	}
	int ans = -1, curr = 0, sum = 0;
	sum = accumulate(dp[0].begin(), dp[0].end(), 0);
	if (sum == 0) show(-1);
	if (sum > 1) show(1);
	fori(i, 0, k - 1) {
		int p = lower_bound(a[i + 1].begin(), a[i + 1].end(), a[i][curr]) - a[i + 1].begin();
		sum = 0;
		fori(j, p, SZ(a[i + 1]))
			sum += dp[i + 1][j];
		if (sum == 0) show(-1);
		if (sum > 1) show(1);
		curr = p;
	}
	show(0);
	return 0;
}

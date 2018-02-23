/*
ID: yefri.g1
PROG: ariprog
LANG: C++
*/
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 2 * 250 * 250 + 10;

int main() {
  ifstream fin ("ariprog.in");
  ofstream fout ("ariprog.out");
	int n, m; fin >> n >> m;
	bitset<MX> bs;
	vi v;
	for (int i = 0; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			v.push_back(i * i + j * j);
			bs[i * i + j * j] = 1;
		}
	}
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	int sz = v.size();
	vector<ii> ans;
	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			int a = v[i], b = v[j] - a;
			int f = 1;
			for (int k = 0; k < n && f; k++)
				f &= a + k * b < MX && bs[a + k * b];
			if (f)
				ans.push_back(ii(b, a));
		}
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			fout << ans[i].second << " " << ans[i].first << endl;
	} else {
		fout << "NONE" << endl;
	}
	return 0;
}
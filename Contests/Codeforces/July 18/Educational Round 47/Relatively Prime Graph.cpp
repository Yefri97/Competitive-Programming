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
	int n, m; cin >> n >> m;
	vector<ii> edges;
	if (m < n - 1) { cout << "Impossible" << endl; return 0; }
	fori(i, 1, n)
		edges.push_back(ii(i, i + 1));
	m -= n - 1;
	for (int i = 1; m > 0 && i <= n; i++) {
		for (int j = i + 2; m > 0 && j <= n; j++) {
			if (__gcd(i, j) == 1) {
				edges.push_back(ii(i, j));
				m--;
			}
		}
	}
	if (m > 0) { cout << "Impossible" << endl; return 0; }
	cout << "Possible" << endl;
	fori(i, 0, edges.size())
		cout << edges[i].first << " " << edges[i].second << endl;
	return 0;
}

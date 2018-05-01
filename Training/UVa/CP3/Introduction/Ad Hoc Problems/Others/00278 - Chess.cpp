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

int n, m, row[20];

bool can(int id, int k) {
	fori(i, 0, id)
		if (row[i] == k || abs(i - id) == abs(row[i] - k))
			return false;
	return true;
}

int solver(int id) {
	if (id == m) return 0;
	int ans = 0;
	fori(k, 0, n) {
		if (can(id, k)) {
			row[id] = k;
			ans = max(ans, solver(id + 1) + 1);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		char c; cin >> c;
		cin >> n >> m;
		if (c == 'r')
			cout << min(n, m) << endl;
		else if (c == 'k')
			cout << (n * m + 1) / 2 << endl;
		else if (c == 'K')
			cout << ((n + 1) / 2) * ((m + 1) / 2) << endl;
		else
			cout << solver(0) << endl;
	}
	return 0;
}
// Iterative (One Loop, Linear Scan)
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define SQ(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << setfill('0');
	vector<vi> ans = {{0, 1, 81}, 
										{0, 1, 2025, 3025, 9801},
										{0, 1, 88209, 494209, 998001},
										{0, 1, 4941729, 7441984, 24502500, 25502500, 52881984, 60481729, 99980001}};
	int n;
	while (cin >> n) {
		int idx = n / 2 - 1;
		fori(i, 0, ans[idx].size())
			cout << setw(n) << ans[idx][i] << endl;
	}
	return 0;
}
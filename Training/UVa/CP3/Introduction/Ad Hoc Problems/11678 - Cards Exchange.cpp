#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 1e5 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m && (n || m)) {
		vector< vi > freq(2, vi(MX));
		fori(i, 0, n) {
			int x; cin >> x; x--;
			freq[0][x]++;
		}
		fori(i, 0, m) {
			int x; cin >> x; x--;
			freq[1][x]++;
		}
		int a = 0, b = 0;
		fori(i, 0, MX)
			a += freq[0][i] > 0 && freq[1][i] == 0;
		fori(i, 0, MX)
			b += freq[1][i] > 0 && freq[0][i] == 0;
		cout << min(a, b) << endl;
	}
	return 0;
}

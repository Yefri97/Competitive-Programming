// Time: 07:22min
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	while (cin >> q && q) {
		int xo, yo; cin >> xo >> yo;
		while (q--) {
			int x, y; cin >> x >> y;
			int dx = x - xo, dy = y - yo;
			if (dx == 0 || dy == 0) {
				cout << "divisa" << endl;
			} else {
				cout << (dy > 0 ? "N" : "S");
				cout << (dx > 0 ? "E" : "O");
				cout << endl;
			}
		}
	}
	return 0;
}
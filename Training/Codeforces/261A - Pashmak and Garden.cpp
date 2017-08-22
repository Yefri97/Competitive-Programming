#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2 || y1 == y2) {
		if (x1 == x2) {
			int d = abs(y2 - y1);
			if (x1 + d <= 1000) {
				cout << x1 + d << " " << y1 << " " << x2 + d << " " << y2 << endl;
			} else if (x1 - d >= -1000) {
				cout << x1 - d << " " << y1 << " " << x2 - d << " " << y2 << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			int d = abs(x2 - x1);
			if (y1 + d <= 1000) {
				cout << x1 << " " << y1 + d << " " << x2 << " " << y2 + d << endl;
			} else if (y1 - d >= -1000) {
				cout << x1 << " " << y1 - d << " " << x2 << " " << y2 - d << endl;
			} else {
				cout << -1 << endl;
			}
		}
	} else {
		if (abs(x2 - x1) == abs(y2 - y1)) {
			if (y2 - y1 == x2 - x1) {
				cout << min(x1, x2) << " " << max(y1, y2) << " " << max(x1, x2) << " " << min(y1, y2) << endl;
			} else {
				cout << min(x1, x2) << " " << min(y1, y2) << " " << max(x1, x2) << " " << max(y1, y2) << endl;
			}
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
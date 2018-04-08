#include <bits/stdc++.h>
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int area; cin >> area;
		for (int i = 0; i < (area + 8) / 9; i++) {
			set<ii> s;
			while (true) {
				int cx = 10 + 3 * i, cy = 10;
				cout << cx << " " << cy << endl;
				int rx, ry; cin >> rx >> ry;
				s.insert(ii(rx, ry));
				if (s.size() == 9) break;
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	int up = oo, dw = -oo, le = oo, ri = -oo;
	fori(i, 0, n) {
		fori(j, 0, m) {
			char c; cin >> c;
			if (c == 'W') continue;
			up = min(up, i);
			dw = max(dw, i);
			le = min(le, j);
			ri = max(ri, j);
		}
	}
	cout << (up + dw) / 2 + 1 << " " << (le + ri) / 2 + 1 << endl;
	return 0;
}

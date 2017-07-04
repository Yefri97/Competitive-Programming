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
	int n, sx, sy, ex, ey; cin >> n >> sx >> sy >> ex >> ey;
	string s; cin >> s;
	int dx = ex - sx, dy = ey - sy;
	int t = 0;
	while (t < n && (dx != 0 || dy != 0)) {
		char c = s[t];
		if (c == 'N' && dy > 0) dy--;
		if (c == 'E' && dx > 0) dx--;
		if (c == 'S' && dy < 0) dy++;
		if (c == 'W' && dx < 0) dx++;
		t++;
	}
	if (dx == 0 && dy == 0) {
		cout << t << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
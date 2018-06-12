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

const int oo = 1e9, mxn = 100010;

struct point {
	int d, x, y;
	point() {}
	point(int _d, int _x, int _y) : d(_d), x(_x), y(_y) {}
	bool operator < (point o) { return d < o.d; }
};

point sockets[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	fori(i, 0, m) {
		int x, y; cin >> x >> y;
		sockets[i] = point((y == 0 || x == n ? x + y : 4 * n - (x + y)), x, y);
	}
	sort(sockets, sockets + m);
	int ans = oo;
	fori(i, 0, m) {
		int nxt = (i + k - 1) % m, dist;
		if (nxt < i && sockets[nxt].d == sockets[i].d) dist = 4 * n;
		else dist = mod(sockets[(i + k - 1) % m].d - sockets[i].d, 4 * n);
		ans = min(ans, dist);
	}
	cout << ans << endl;
	return 0;
}
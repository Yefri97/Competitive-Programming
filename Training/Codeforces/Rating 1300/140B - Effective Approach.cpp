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

const int INF = 1e9, MAXN = 100010;

int pos[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x; x--;
		pos[x] = i;
	}
	ll v = 0, p = 0;
	int m; cin >> m;
	while (m--) {
		int q; cin >> q; q--;
		v += pos[q] + 1;
		p += n - pos[q];
	}
	cout << v << " " << p << endl;
	return 0;
}
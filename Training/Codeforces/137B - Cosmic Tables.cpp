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

const int oo = 1e9, mxn = 1000;
int A[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> A[i][j];
	vi row(n), col(m);
	fori(i, 0, n) row[i] = i;
	fori(i, 0, m) col[i] = i;
	while (q--) {
		char c; cin >> c;
		int x, y; cin >> x >> y; x--; y--;
		if (c == 'c') {
			swap(col[x], col[y]);
		} else if (c == 'r') {
			swap(row[x], row[y]);
		} else {
			cout << A[row[x]][col[y]] << endl;
		}
	}
	return 0;
}
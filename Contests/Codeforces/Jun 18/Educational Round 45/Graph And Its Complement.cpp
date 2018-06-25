#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 1000;

int g[MN][MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b; cin >> n >> a >> b;
	if (n == 2 && a == b || n == 3 && a == 1 && b == 1){
		cout << "NO" << endl;
	} else {
		if (a > 1 && b > 1) { cout << "NO" << endl; return 0; }
		cout << "YES" << endl;
		int c = (a == 1 ? 0 : 1);
		int d = (a == 1 ? n - b : n - a);
		fori(i, 0, n) fori(j, 0, n) g[i][j] = (i == j ? 0 : 1 - c);
		fori(i, 0, d)
			g[i][i + 1] = g[i + 1][i] = c;
		fori(i, 0, n) {
			fori(j, 0, n)
				cout << g[i][j];
			cout << endl;
		}
	}
	return 0;
}

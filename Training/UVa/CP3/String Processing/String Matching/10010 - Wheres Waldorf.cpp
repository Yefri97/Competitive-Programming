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

const int oo = 1e9, mxn = 60;

int n, m;
char board[mxn][mxn];

int mi[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

ii solver(string s) {
	fori(i, 0, n) {
		fori(j, 0, m) {
			fori(k, 0, 8) {
				bool flag = true;
				fori(l, 0, s.size()) {
					int ni = i + l * mi[k], nj = j + l * mj[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) { flag = false; break; }
					flag &= (tolower(board[ni][nj]) == tolower(s[l]));
				}
				if (flag) return ii(i, j);
			}
		}
	}
	return ii(-1, -1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> board[i][j];
		int q; cin >> q;
		while (q--) {
			string s; cin >> s;
			ii ans = solver(s);
			cout << ans.first + 1 << " " << ans.second + 1 << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}
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
typedef pair<int, ii> iii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 100;

int n;
char board[mxn][mxn];

int mi[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

iii solver(string s) {
	fori(i, 0, n) {
		fori(j, 0, n) {
			fori(k, 0, 8) {
				bool found = true;
				fori(l, 0, s.size()) {
					int ni = i + l * mi[k], nj = j + l * mj[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= n) { found = false; break; }
					found &= (board[ni][nj] == s[l]);
				}
				if (found) return iii(k, ii(i, j));
			}
		}
	}
	return iii(-1, ii(-1, -1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n)
		fori(j, 0, n)
			cin >> board[i][j];
	string q;
	while (cin >> q && q != "0") {
		iii ans = solver(q);
		if (ans.first != -1) {
			int i = ans.second.first, j = ans.second.second, k = ans.first, m = q.size(); i++, j++;
			cout << i << "," << j << " " << i + mi[k] * (m - 1) << "," << j + mj[k] * (m - 1) << endl;
		} else {
			cout << "Not found" << endl;
		}
	}
	return 0;
}
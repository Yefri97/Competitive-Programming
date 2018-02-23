#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<char> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int n, m;

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

bool win(char p1, char p2) { 
	return p1 == 'R' && p2 == 'S' || p1 == 'S' && p2 == 'P' || p1 == 'P' && p2 == 'R';
}

void updateBoard(vvi oldb, vvi &newb) {
	fori(i, 0, n) {
		fori(j, 0, m) {
			fori(k, 0, 4) {
				int ni = i + mi[k], nj = j + mj[k];
				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
				if (win(oldb[i][j], oldb[ni][nj]))
					newb[ni][nj] = oldb[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int k; cin >> n >> m >> k;
		vvi board(n, vi(m));
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> board[i][j];
		while (k--)
			updateBoard(board, board);
		fori(i, 0, n) {
			fori(j, 0, m) {
				cout << board[i][j];
			}
			cout << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}
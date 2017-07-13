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

const int oo = 1e9, mxn = 210;
char board[mxn][mxn];

int h, w;
int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

void flood_fill(int i, int j, int d, int c) {
	board[i][j] = d;
	fori(k, 0, 4) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= h || nj < 0 || nj > w) continue;
		if (board[ni][nj] == c)
			flood_fill(ni, nj, d, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	while (cin >> h >> w && h) {
		fori(i, 0, h) {
			fori(j, 0, w) {
				char c; cin >> c;
				int num = (isalpha(c) ? 10 + (c - 'a') : c - '0');
				fori(k, 0, 4) {
					board[i][4 * (j + 1) - k - 1] = num & 1;
					num >>= 1;
				}
			}
		}
		w *= 4;
		fori(i, 0, h)
			fori(j, 0, w)
				if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && board[i][j] == 0)
					flood_fill(i, j, -1, 0);
		vi num_cc;
		int id = 2;
		fori(i, 0, h) {
			fori(j, 0, w) {
				if (board[i][j] == 1) {
					flood_fill(i, j, id, 1);
					num_cc.push_back(0);
					id++;
				} else if(board[i][j] == 0) {
					num_cc[board[i][j - 1] - 2]++;
					flood_fill(i, j, -1, 0);
				}
			}
		}
		vector<char> ans;
		fori(i, 0, num_cc.size()) {
			int x = num_cc[i];
			if(x == 0) ans.push_back('W');
			if(x == 1) ans.push_back('A');
			if(x == 2) ans.push_back('K');
			if(x == 3) ans.push_back('J');
			if(x == 4) ans.push_back('S');
			if(x == 5) ans.push_back('D');
		}
		sort(ans.begin(), ans.end());
		cout << "Case " << ++cs << ": ";
		fori(i, 0, ans.size())
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
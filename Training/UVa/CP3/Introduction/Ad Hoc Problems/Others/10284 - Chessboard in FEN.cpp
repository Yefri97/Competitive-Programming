#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, sz = 8;

vii movements(int i, int j, vvc &board) {
	vii ans;
	ans.push_back(ii(i, j));
	char p = board[i][j];
	if (p == 'r') {
		int mi[] = {0, -1, 0, 1};
		int mj[] = {-1, 0, 1, 0};
		fori(k, 0, 4) {
			for (int x = 1; true; x++) {
				int ni = i + x * mi[k], nj = j + x * mj[k];
				if (ni < 0 || ni >= sz || nj < 0 || nj >= sz || board[ni][nj] != '.') break;
				ans.push_back(ii(ni, nj));
			}
		}
	}
	if (p == 'b') {
		int mi[] = {-1, -1, 1, 1};
		int mj[] = {-1, 1, 1, -1};
		fori(k, 0, 4) {
			for (int x = 1; true; x++) {
				int ni = i + x * mi[k], nj = j + x * mj[k];
				if (ni < 0 || ni >= sz || nj < 0 || nj >= sz || board[ni][nj] != '.') break;
				ans.push_back(ii(ni, nj));
			}
		}
	}
	if (p == 'q') {
		int mi[] = {0, -1, 0, 1, -1, -1, 1, 1};
		int mj[] = {-1, 0, 1, 0, -1, 1, 1, -1};
		fori(k, 0, 8) {
			for (int x = 1; true; x++) {
				int ni = i + x * mi[k], nj = j + x * mj[k];
				if (ni < 0 || ni >= sz || nj < 0 || nj >= sz || board[ni][nj] != '.') break;
				ans.push_back(ii(ni, nj));
			}
		}
	}
	if (p == 'n') {
		int mi[] = {-1, -2, -2, -1, 1, 2, 2, 1};
		int mj[] = {-2, -1, 1, 2, 2, 1, -1, -2};
		fori(k, 0, 8) {
			int ni = i + mi[k], nj = j + mj[k];
			if (ni < 0 || ni >= sz || nj < 0 || nj >= sz || board[ni][nj] != '.') continue;
			ans.push_back(ii(ni, nj));
		}
	}
	if (p == 'k') {
		int mi[] = {0, -1, 0, 1, -1, -1, 1, 1};
		int mj[] = {-1, 0, 1, 0, -1, 1, 1, -1};
		fori(k, 0, 8) {
			int ni = i + mi[k], nj = j + mj[k];
			if (ni < 0 || ni >= sz || nj < 0 || nj >= sz || board[ni][nj] != '.') continue;
			ans.push_back(ii(ni, nj));
		}
	}
	if (p == 'p' || p == 'P') {
		int mi[] = {1, 1};
		int mj[] = {-1, 1};
		fori(k, 0, 2) {
			int x = (p == 'p' ? 1 : -1);
			int ni = i + x * mi[k], nj = j + mj[k];
			if (ni < 0 || ni >= sz || nj < 0 || nj >= sz || board[ni][nj] != '.') continue;
			ans.push_back(ii(ni, nj));
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (cin >> line) {
		vvc board(sz, vc(sz, '.'));
		int i = 0, j = 0;
		for (char c : line) {
			if (c == '/') {
				j = 0;
				i++;
			} else if (isalpha(c)) {
				board[i][j] = tolower(c);
				if (c == 'P') board[i][j] = c;
				j++;
			} else {
				j += (c - '0');
			}
		}
		vvi attacked(sz, vi(sz));
		fori(i, 0, sz) {
			fori(j, 0, sz) {
				if (board[i][j] == '.') continue;
				vii movs = movements(i, j, board);
				for (auto m : movs)
					attacked[m.first][m.second] = 1;
			}
		}
		int ans = 0;
		fori(i, 0, sz)
			fori(j, 0, sz)
				ans += (attacked[i][j] == 0);
		cout << ans << endl;
	}
	return 0;
}
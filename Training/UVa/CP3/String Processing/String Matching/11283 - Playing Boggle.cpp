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
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

string w;

char board[5][5];
int taken[5][5];

int points[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};

int mi[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check(int i, int j, int id) {
	if (id == w.size()) return true;
	fori(k, 0, 8) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= 4 || nj < 0 || nj >= 4 || board[ni][nj] != w[id]) continue;
		if (!taken[ni][nj]) {
			taken[ni][nj] = 1;
			bool ans = check(ni, nj, id + 1);
			taken[ni][nj] = 0;
			if (ans) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		fori(i, 0, 4)
			fori(j, 0, 4)
				cin >> board[i][j];
		int m; cin >> m;
		int ans = 0;
		while (m--) {
			cin >> w;
			bool found = false;
			for (int i = 0; i < 4 && !found; i++) {
				for (int j = 0; j < 4 && !found; j++) {
					if (board[i][j] == w[0]) {
						taken[i][j] = 1;
						found = check(i, j, 1);
						taken[i][j] = 0;
						if (found)
							ans += points[(int)w.size()];
					}
				}
			}
		}
		cout << "Score for Boggle game #" << ++cs << ": " << ans << endl;
	}
	return 0;
}
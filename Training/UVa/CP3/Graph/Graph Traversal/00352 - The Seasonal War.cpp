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

const int oo = 1e9;

int n;
char board[50][50];

int mi[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int mj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void floodFill(int i, int j, char c1, char c2) {
	board[i][j] = c1;
	fori(k, 0, 8) {
		int ni = i + mi[k], nj = j + mj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (board[ni][nj] == c2)
			floodFill(ni, nj, c1, c2);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	while (cin >> n) {
		fori(i, 0, n)
			fori(j, 0, n)
				cin >> board[i][j];
		int ans = 0;
		fori(i, 0, n) {
			fori(j, 0, n) {
				if (board[i][j] == '1') {
					floodFill(i, j, '0', '1');
					ans++;
				}
			}
		}
		cout << "Image number " << ++cs << " contains " << ans << " war eagles." << endl;
	}
	return 0;
}
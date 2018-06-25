#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 50;

char grid[MN][MN];
string color = "ABCD";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(grid, '.', sizeof grid);
	vi k(4);
	fori(i, 0, 4)
		cin >> k[i];
	int n = 50, m = n / 2;
	cout << n << " " << n << endl;
	fori(i, 0, n) {
		fori(j, 0, n) {
			int c1 = 2 * (i / m) + (j / m), c2 = (c1 + 1) % 4;
			if (i % m == 0 || (i + 1) % m == 0 || j % m == 0 || (j + 1) % m == 0) {
				grid[i][j] = color[c1];
			} else {
				if (k[c2] > 1 && (i + j) % 3 == 0) {
					grid[i][j] = color[c2];
					k[c2]--;
				} else {
					grid[i][j] = color[c1];
				}
			}
		}
	}
	fori(i, 0, n) {
		fori(j, 0, n)
			cout << grid[i][j];
		cout << endl;
	}
	return 0;
}

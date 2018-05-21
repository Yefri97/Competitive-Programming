#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 110;

char A[MN][MN];
int B[MN][MN];

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n) {
		fori(j, 0, m) {
			cin >> A[i][j];
			if (A[i][j] == '*') B[i][j] = -1;
		}
	}
	fori(i, 0, n) {
		fori(j, 0, m) {
			if (B[i][j] != -1) continue;
			fori(k, 0, 8) {
				int ni = i + di[k], nj = j + dj[k];
				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
				if (B[ni][nj] == -1) continue;
				B[ni][nj]++;
			}
		}
	}
	int ok = 1;
	fori(i, 0, n) {
		fori(j, 0, m) {
			if (A[i][j] == '*') continue;
			if (A[i][j] == '.') ok &= (B[i][j] == 0);
			else ok &= ((A[i][j] - '0') == B[i][j]);
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}

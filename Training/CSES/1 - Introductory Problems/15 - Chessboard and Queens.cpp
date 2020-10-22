#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n = 8;
	char board[n][n];
	fori(i, 0, n) fori(j, 0, n)
		cin >> board[i][j];
	vector<int> a(n);
	fori(i, 0, n) a[i] = i;
	int ans = 0;
	do {
		int ok = 1;
		fori(i, 0, n) {
			ok &= (board[i][a[i]] != '*');
			fori(j, 0, i) {
				int dx = i - j;
				int dy = abs(a[i] - a[j]);
				ok &= (dx != dy);
			}
		}
		ans += ok;
	} while (next_permutation(all(a)));
	cout << ans << endl;
	return 0;
}

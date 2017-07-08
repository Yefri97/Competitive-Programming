#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

char board[5][5];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, 4)
		fori(j, 0, 4)
			cin >> board[i][j];
	bool ans = false;
	fori(i, 0, 3) {
		fori(j, 0, 3) {
			vi v(2);
			v[(board[i][j] == '.')]++;
			v[(board[i][j+1] == '.')]++;
			v[(board[i+1][j] == '.')]++;
			v[(board[i+1][j+1] == '.')]++;
			ans |= (abs(v[0] - v[1]) != 0);
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
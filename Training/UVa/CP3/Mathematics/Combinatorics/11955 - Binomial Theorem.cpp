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

const int oo = 1e9, mxn = 51;

ll C[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, mxn) C[i][0] = C[0][i] = 1;
	fori(i, 1, mxn)
		fori(j, 1, mxn)
			C[i][j] = C[i - 1][j] + C[i][j - 1];
	int t, cs = 0; cin >> t;
	while (t--) {
		string input; cin >> input;
		string a, b;
		int len = input.size(), it = 0;
		it++; // (
		while (input[it] != '+') a.push_back(input[it++]);
		it++; // +
		while (input[it] != ')') b.push_back(input[it++]);
		it++; // )
		it++; // ^
		int k = 0;
		while (it < len) k = 10 * k + (input[it++] - '0');
		cout << "Case " << ++cs << ": ";
		for (int i = 0; i <= k; i++) {
			int j = k - i;
			if (i) cout << "+";
			if (C[k - i][i] != 1) cout << C[k - i][i] << "*";
			if (j) {
				cout << a;
				if (j != 1) cout << "^" << j;
				if (i) cout << "*";
			}
			if (i) {
				cout << b;
				if (i != 1) cout << "^" << i;
			}
		}
		cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

char A[5][110];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(A, '.', sizeof A);
	int n, k; cin >> n >> k;
	cout << "YES" << endl;
	fori(i, 0, 2)
		fori(j, 0, (n - 2) / 2)
			if (k > 1) A[i + 1][j + 1] = A[i + 1][n - j - 2] = '#', k -= 2;
	if (k == 1) A[1][n / 2] = '#';
	if (k == 2) A[1][n / 2] = A[2][n / 2] = '#';
	fori(i, 0, 4) {
		fori(j, 0, n)
			cout << A[i][j];
		cout << endl;
	}
	return 0;
}

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

const int oo = 1e9, mxn = 110;
int A[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n) {
		fori(j, 0, m) {
			char c; cin >> c;
			A[i][j] = (c - '0');
		}
	}
	vi v(n);
	fori(j, 0, m) {
		int max_val = 0;
		fori(i, 0, n)
			max_val = max(max_val, A[i][j]);
		fori(i, 0, n)
			if (A[i][j] == max_val)
				v[i] = 1;
	}
	cout << accumulate(v.begin(), v.end(), 0) << endl;
	return 0;
}
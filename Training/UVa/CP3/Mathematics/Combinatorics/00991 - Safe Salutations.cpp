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

const int oo = 1e9, mxn = 15;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// Catalan Numbers
	vi v(mxn);
	v[0] = 1;
	fori(i, 1, mxn)
		v[i] = ((2 * i) * (2 * i - 1) * v[i - 1]) / ((i + 1) * i);
	int n, first = 1;
	while (cin >> n) {
		if (!first) cout << endl; first = 0;
		cout << v[n] << endl;
	}
	return 0;
}
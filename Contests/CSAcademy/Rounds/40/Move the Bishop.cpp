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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
	if (r1 == r2 && c1 == c2) {
		cout << 0 << endl;
	} else if ((abs(r1 - r2) + abs(c1 - c2)) % 2) {
		cout << -1 << endl;
	} else if (abs(r1 - r2) == abs(c1 - c2)) {
		cout << 1 << endl;
	} else {
		cout << 2 << endl;
	}
	return 0;
}
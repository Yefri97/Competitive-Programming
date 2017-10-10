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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int r, n, cs = 0;
	while (cin >> r >> n && (r + n)) {
		cout << "Case " << ++cs << ": ";
		if (r > n * 27) {
			cout << "impossible" << endl;
		} else {
			cout << (r - 1) / n << endl;
		}
	}
	return 0;
}
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
	int n, r1, c1, r2, c2, cs = 0;
	while (cin >> n >> r1 >> c1 >> r2 >> c2 && n) {
		int m = 2 * n - 1;
		cout << "Case " << ++cs << ":" << endl;
		fori(i, r1, r2 + 1) {
			fori(j, c1, c2 + 1) {
				int dx = abs((i % m) - (n - 1)), dy = abs((j % m) - (n - 1));
				cout << (char)(dx + dy >= n ? '.' : ((dx + dy) % 26) + 'a');
			}
			cout << endl;
		}
	}
	return 0;
}
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
	int n; cin >> n;
	int p = -1, q = -1;
	for (int i = 0; 7 * i <= n; i++) {
		if ((n - 7 * i) % 4 == 0)
			p = (n - 7 * i) / 4, q = i;
	}
	if (p == -1)
		cout << -1 << endl;
	else {
		fori(i, 0, p) cout << 4;
		fori(i, 0, q) cout << 7;
		cout << endl;
	}
	return 0;
}
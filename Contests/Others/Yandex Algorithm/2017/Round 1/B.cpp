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

int coins[] = {1, 5, 10, 50, 100, 500, 1000, 5000};

int solver(int x) {
	int ans = 0;
	fori(i, 0, 8) {
		int c = coins[7 - i];
		while (x >= c) {
			x -= c;
			if (c <= 100) ans += c;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a; cin >> n >> a;
	int ans = -oo;
	fori(i, 0, 5001) {
		//if (n - i < 2 * a) continue;
		//ans = max(ans, solver(a + i) + solver(n - (a + i)));
		int x = solver(i);
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
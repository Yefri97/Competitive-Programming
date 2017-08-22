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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	bool ans = true;
	int c25 = 0, c50 = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		if (x == 25) {
			c25++;
		} else if (x == 50) {
			if (c25) {
				c25--;
				c50++;
			} else {
				ans = false;
			}
		} else {
			if (c50) {
				if (c25) {
					c50--;
					c25--;
				} else {
					ans = false;
				}
			} else if (c25 >= 3) {
				c25 -= 3;
			} else {
				ans = false;
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
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

const int oo = 1e9, mxn = 6000;

bool go(int k, int n) {
	if (9 * k >= n) return true;
	fori(i, 2, 10)
		if (!go(k * i, n)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	/*fori(i, 2, mxn) {
		bool ans = go(1, i);
		if (!ans) cout << i << endl;
	}*/
	ll n;
	while (cin >> n) {
		bool ans = true;
		ll pw = 1;
		while (pw < 2 * n) {
			if (2 * n <= 2 * pw) ans = false;
			pw *= 18;
		}
		cout << (ans ? "Stan" : "Ollie") << " wins." << endl;
	}
	return 0;
}
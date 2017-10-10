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

bool check(int n, int x) {
	fori(i, 0, x) {
		if ((x - 1) * (n - 1) % x) return false;
		n = ((x - 1) * (n - 1)) / x;
	}
	return n % x == 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n >= 0) {
		int ans = -1;
		for (int i = 1; i * i < n; i++) {
			if ((n - 1) % i) continue;
			int j = (n - 1) / i;
			if (check(n, i)) ans = max(ans, i);
			if (check(n, j)) ans = max(ans, j);
		}
		if (ans == 1) ans = -1;
		cout << n << " coconuts, ";
		if (ans == -1) {
			cout << "no solution" << endl;
		} else {
			cout << ans << " people and 1 monkey" << endl;
		}
	}
	return 0;
}
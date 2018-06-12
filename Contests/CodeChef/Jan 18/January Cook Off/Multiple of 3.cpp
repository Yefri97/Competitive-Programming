#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		int a, b; cin >> a >> b;
		int c = (a + b) % 10;
		ll k = n - 3;

		vi v(4);
		fori(i, 0, 4)
			v[i] = (((1 << (i + 1)) * c) % 10) % 3;

		int acc = accumulate(v.begin(), v.end(), 0);
		int sum = 0;
		sum = (sum + a + b + c) % 3;
		sum = (sum + (acc * (k / 4))) % 3;
		fori(i, 0, k % 4)
			sum = (sum + v[i]) % 3;

		cout << (sum == 0 ? "YES" : "NO") << endl;
	}
	return 0;
}
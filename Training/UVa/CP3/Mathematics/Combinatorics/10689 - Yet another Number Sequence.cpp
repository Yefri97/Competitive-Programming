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
	vector<int> fib(15001);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 15000; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 10000;
	int t; cin >> t;
	while (t--) {
		int a, b, n, m; cin >> a >> b >> n >> m;
		m = pow(10, m);
		int ans = n == 0 ? a % m : ((a * fib[(n - 1) % 15000]) + (b * fib[n % 15000])) % m;
		cout << ans << endl;
	}
	return 0;
}
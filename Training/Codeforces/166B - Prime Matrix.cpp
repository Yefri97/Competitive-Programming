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

const int oo = 1e9, mxn = 510;

int board[mxn][mxn];
vector<ll> primes;
bitset<200010> bs;

int next_prime(int n) {
	return *(lower_bound(primes.begin(), primes.end(), n));
}

void sieve(ll n) {
	bs.set();
	for (ll i = 2; i <= n; i++) if (bs.test(i)) {
		for (ll j = i * i; j <= n; j += i) bs.reset(j);
		primes.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(200000);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> board[i][j];
	int ans = oo;
	fori(i, 0, n) {
		int acc = 0;
		fori(j, 0, m)
			acc += next_prime(board[i][j]) - board[i][j];
		ans = min(ans, acc);
	}
	fori(j, 0, m) {
		int acc = 0;
		fori(i, 0, n)
			acc += next_prime(board[i][j]) - board[i][j];
		ans = min(ans, acc);
	}
	cout << ans << endl;
	return 0;
}
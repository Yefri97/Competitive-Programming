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

vector<ll> tprimes;
bitset<1000010> bs;

void sieve(int n) {
	bs.set();
	for (ll i = 2; i <= n; i++) if (bs.test(i)) {
		for (ll j = i * i; j <= n; j += i) bs.reset(j);
		tprimes.push_back(i * i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(1000000);
	int n; cin >> n;
	fori(i, 0, n) {
		ll x; cin >> x;
		bool ans = binary_search(tprimes.begin(), tprimes.end(), x);
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
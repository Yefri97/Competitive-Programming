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

const int oo = 1e9, k = 2e7;

bitset<k + 10> bs;
vi primes;

void sieve(ll sz) {
	bs.set();
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(k);
	vii ans;
	for (int i = 1; i < (int)primes.size(); i++)
		if (primes[i] - primes[i - 1] == 2)
			ans.push_back(ii(primes[i - 1], primes[i]));
	int n;
	while (cin >> n) { n--;
		cout << "(" << ans[n].first << ", " << ans[n].second << ")" << endl;
	}
	return 0;
}
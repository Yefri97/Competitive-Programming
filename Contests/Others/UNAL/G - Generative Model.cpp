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

const int oo = 1e9, kmod = 1e9 + 7;

int memo[20];
vi B;

vi primeFactors(ll n) {
	vi factors;
	ll pf = 2;
	while (pf * pf <= n) {
		while (n % pf == 0) { n /= pf; factors.push_back(pf); }
		pf++;
	}
	if (n != 1) factors.push_back(n);
	return factors;
}

int go(int id) {
	if (id == B.size()) return 1;
	if (id == B.size() - 1) return B[id] != 0;
	if (B[id] == 0) return 0;
	if (memo[id] != -1) return memo[id];
	int ans = go(id + 1);
	if (B[id] * 10 + B[id + 1] <= 26)
		ans += go(id + 2);
	return memo[id] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		vi factors = primeFactors(n);
		B.clear();
		fori(i, 0, factors.size()) {
			int x = factors[i];
			while (x) {
				B.push_back(x % 10);
				x /= 10;
			}
		}
		sort(B.begin(), B.end());
		int ans = 0;
		do {
			memset(memo, -1, sizeof memo);
			ans = (ans + go(0)) % kmod;
		} while (next_permutation(B.begin(), B.end()));
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 10010, MN = 5010;

bitset<MX> bs;
vi primes;

void sieve() {
	bs.set();
	for (ll i = 2; i < MX; i++) if (bs[i]) {
		for (ll j = i * i; j < MX; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

int simple(int x) {
	int idx = 0, pf = primes[0], ans = 1;
	while (pf * pf <= x) {
		int pow = 0;
		while (x % pf == 0) { x /= pf; pow++; }
		if (pow % 2 == 1) ans *= pf;
		pf = primes[++idx];
	}
	ans *= x;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	fori(i, 0, n) {
		int x = v[i], neg = 0;
		if (x < 0) neg = 1;
		if (neg) x *= -1;
		x = simple(x);
		if (neg) x *= -1;
		v[i] = x;
	}
	map<int, int> mapper;
	mapper[0] = 0;
	for (int i = 0, idx = 1; i < n; i++) {
		if (mapper.count(v[i]) == 0) mapper[v[i]] = idx++;
		v[i] = mapper[v[i]];
	}
	vi ans(n);
	for (int i = 0; i < n; i++) {
		int d = 0;
		vi freq(MN);
		for (int j = i; j >= 0; j--) {
			if (v[j] == 0) {
				if (freq[0] == (i - j)) ans[0]++;
				else ans[d - 1]++;
			} else {
				if (freq[v[j]] == 0) d++;
				ans[d - 1]++;
			}
			freq[v[j]]++;
		}
	}
	fori(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}

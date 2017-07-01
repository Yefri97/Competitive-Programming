// Prime Numbers
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

bool isprime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi primes;
	fori(i, 1, 1001)
		if (isprime(i))
			primes.push_back(i);
	int n, c;
	while (cin >> n >> c) {
		int len = 0;
		while (len < primes.size() && primes[len] <= n) len++;
		int x = min(len, (len % 2 == 0 ? 2 * c : 2 * c - 1));
		int idx = (len - x) / 2;
		cout << n << " " << c << ":";
		fori(i, 0, x)
			cout << " " << primes[idx + i];
		cout << endl << endl;
	}
	return 0;
}
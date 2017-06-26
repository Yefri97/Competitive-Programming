// Bonus Feature: Primality Testing
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
	fori(i, 2, n)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while (cin >> s) {
		int acc = 0;
		fori(i, 0, s.size())
			acc += (isupper(s[i]) ? s[i] - 'A' + 27 : s[i] - 'a' + 1);
		cout << (isprime(acc) ? "It is a prime word." : "It is not a prime word.") << endl;
	}
	return 0;
}
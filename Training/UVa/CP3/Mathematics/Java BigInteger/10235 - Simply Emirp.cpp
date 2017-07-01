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
	string n;
	while (cin >> n) {
		int a = atoi(n.c_str());
		reverse(n.begin(), n.end());
		int b = atoi(n.c_str());
		bool ipa = isprime(a), ipb = (a == b ? false : isprime(b));
		if (ipa && ipb)
			cout << a << " is emirp." << endl;
		else if (ipa && !ipb)
			cout << a << " is prime." << endl;
		else
			cout << a << " is not prime." << endl;
	}
	return 0;
}
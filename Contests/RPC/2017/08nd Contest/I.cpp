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

bool solver(int x) {
	for (int p = 2; p * p <= x; p++) {
		if (x % p == 0) {
			while (x % p == 0) x /= p;
			return (x == 1);
		}
	}
	return (x != 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	while (cin >> q) {
		bool ans = solver(q);
		cout << (ans ? "yes" : "no") << endl;
	}
	return 0;
}
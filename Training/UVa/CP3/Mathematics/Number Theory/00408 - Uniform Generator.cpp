#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int step, mod;
	while (cin >> step >> mod) {
		bool ans = __gcd(step, mod) == 1;
		cout << setw(10) << step << setw(10) << mod << "    ";
		if (ans) cout << "Good Choice" << endl;
		else cout << "Bad Choice" << endl;
		cout << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, a = 32;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		ll h, x, z; cin >> h >> x >> z;
		if (a * x * x <= 2 * h * z * z)
			cout << "Rahul" << endl;
		else
			cout << "Raj" << endl;
	}
	return 0;
}

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
	int tc; cin >> tc;
	fori(t, 0, tc) {
		cout << "Case #" << t + 1 << ": ";
		int n; cin >> n;
		vi p(n + 1);
		fori(i, 0, n + 1)
			cin >> p[i];
		if (n % 2) {
			cout << 1 << endl;
			cout << 0 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}

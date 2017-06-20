// Sistems or Sequences
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

int solver(ll a, ll l) {
	int target = 0;
	while (a != 1 && a <= l) {
		if ((a % 2) == 0)
			a = a / 2;
		else
			a = 3 * a + 1;
		target++;
	}
	if (a == 1) target++;
	return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, l, cs = 0;
	while (cin >> a >> l && (a >= 0 && l >= 0)) {
		cout << "Case " << ++cs << ": ";
		cout << "A = " << a << ", ";
		cout << "limit = " << l << ", ";
		cout << "number of terms = " << solver(a, l) << endl;
	}
	return 0;
}
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int acca = 0, accb = 0;
	bool flag = false;
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		if ((a + b) % 2) flag = true;
		acca += a;
		accb += b;
	}
	if (acca % 2 == 0 && accb % 2 == 0) {
		cout << 0 << endl;
	} else if ((acca + accb) % 2 == 1) {
		cout << -1 << endl;
	} else {
		if (flag)
			cout << 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
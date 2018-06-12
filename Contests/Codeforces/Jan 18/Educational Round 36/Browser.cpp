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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, p, l, r; cin >> n >> p >> l >> r;
	if (l == 1 && r == n) {
		cout << 0 << endl;
	} else if (l == 1) {
		cout << abs(p - r) + 1 << endl;
	} else if (r == n) {
		cout << abs(p - l) + 1 << endl;
	} else {
		cout << min(abs(p - r), abs(p - l)) + r - l + 2 << endl; 
	}
	return 0;
}
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
	int n, a, b; cin >> n >> a >> b;
	fori(i, 0, n) {
		int x; cin >> x;
		a += x;
	}
	fori(i, 0, n) {
		int x; cin >> x;
		b += x;
	}
	cout << (a > b ? 1 : a < b ? 2 : 0) << endl;
	return 0;
}
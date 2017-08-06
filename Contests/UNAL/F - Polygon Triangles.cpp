#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	bool ans = true;
	fori(i, 0, n) {
		int a, b, c; cin >> a >> b >> c;
		ans &= (a + b > c && a + c > b && b + c > a);
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
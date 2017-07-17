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
	int a, b, c, d; cin >> a >> b >> c >> d;
	int x, y;
	if (b * c > a * d) {
		x = b * c - a * d;
		y = b * c;
	} else {
		x = a * d - b * c;
		y = a * d;
	}
	cout << x / __gcd(x, y) << "/" << y / __gcd(x, y) << endl;
	return 0;
}
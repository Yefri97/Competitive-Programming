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
	int x, y, z; cin >> x >> y >> z;
	int a = x + y - z, b = -x + y + z, c = x - y + z;
	if (a < 0 || a % 2 == 1 || b < 0 || b % 2 == 1 || c < 0 || c % 2 == 1)
		cout << "Impossible" << endl;
	else
		cout << a / 2 << " " << b / 2 << " " << c / 2 << endl;
	return 0;
}
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

int x, y, z;

bool solver(int a, int b, int c, int d) {
	for (x = 0; x < 201; x++)
		for (y = 0; y < x; y++)
			for (z = 0; z < y; z++)
				if (a <= x && 2 * a >= x && b <= y && 2 * b >= y && c <= z && 2 * c >= z && d <= z && 2 * d >= z && 2 * d < x && 2 * d < y)
					return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;
	bool ans = solver(a, b, c, d);
	if (ans) {
		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
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

const int oo = 1e9, mxn = 20;

double X1[mxn], X2[mxn], Y1[mxn], Y2[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	char c;
	int n = 0;
	while (cin >> c && c != '*') {
		cin >> X1[n] >> Y1[n] >> X2[n] >> Y2[n];
		n++;
	}
	double x, y;
	for (int p = 1; cin >> x >> y && x != 9999.9 && y != 9999.9; p++) {
		bool b = false;
		fori(i, 0, n) {
			if (X1[i] < x && x < X2[i] && Y2[i] < y && y < Y1[i]) {
				cout << "Point " << p << " is contained in figure " << i + 1 << endl;
				b = true;
			}
		}
		if (!b)
			cout << "Point " << p << " is not contained in any figure" << endl;
	}
	return 0;
}
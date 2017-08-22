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

char type[20];
double figures[20][10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n = 0;
	char c;
	while (cin >> c && c != '*') {
		fori(i, 0, (c == 'r' ? 4 : 3))
			cin >> figures[n][i];
		type[n] = c;
		n++;
	}
	int id = 0;
	double x, y;
	while (cin >> x >> y && x != 9999.9) {
		int has = 0;
		fori(i, 0, n) {
			if (type[i] == 'r') {
				if (figures[i][0] < x && x < figures[i][2] && figures[i][3] < y && y < figures[i][1]) {
					cout << "Point " << id + 1 << " is contained in figure " << i + 1 << endl;
					has = 1;
				}
			} else {
				if (sqrt(sq(x - figures[i][0]) + sq(y - figures[i][1])) < figures[i][2]) {
					cout << "Point " << id + 1 << " is contained in figure " << i + 1 << endl;
					has = 1;
				}
			}
		}
		if (!has)
			cout << "Point " << id + 1 << " is not contained in any figure" << endl;
		id++;
	}
	return 0;
}
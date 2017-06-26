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
	int a, b, c; cin >> a >> b >> c;
	int x, y, z;
	y = 1;
	while (true) {
		if (a % y == 0 && b % y == 0 && a / y * b / y == c) break;
		y++;
	}
	cout << 4 * (a / y + b / y + y) << endl;
	return 0;
}
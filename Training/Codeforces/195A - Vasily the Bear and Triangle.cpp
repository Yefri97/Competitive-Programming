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
	int x, y; cin >> x >> y;
	int z = abs(x) + abs(y);
	if (x > 0 && y > 0) cout << 0 << " " << z << " " << z << " " << 0 << endl;
	if (x < 0 && y > 0) cout << -z << " " << 0 << " " << 0 << " " << z << endl;
	if (x < 0 && y < 0) cout << -z << " " << 0 << " " << 0 << " " << -z << endl;
	if (x > 0 && y < 0) cout << 0 << " " << -z << " " << z << " " << 0 << endl;
	return 0;
}
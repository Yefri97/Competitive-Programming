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

const int oo = 1e9, MX = 1e5;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, m; cin >> a >> m;
	vector<int> seen(MX);
	while (seen[a % m] == 0) {
		seen[a % m] = 1;
		a = (2 * a) % m;
	}
	cout << (a == 0 ? "Yes" : "No") << endl;
	return 0;
}
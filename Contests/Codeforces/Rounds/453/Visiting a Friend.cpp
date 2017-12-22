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

const int oo = 1e9, MX = 100;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi field(MX + 1);
	int n, m; cin >> n >> m;
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		fori(i, a, b)
			field[i] = 1;
	}
	bool ans = true;
	fori(i, 0, m)
		ans &= field[i];
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
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
	int a, b, n; cin >> a >> b >> n;
	int c = mod(- a * 10, b);
	if (c < 10) {
		cout << a << c;
		fori(i, 0, n - 1)
			cout << 0;
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
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

int gauss(int n) { return (n * (n + 1)) / 2; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	int x = m % gauss(n);
	cout << x - gauss((sqrt(8 * (double)x + 1) - 1) * 0.5) << endl;
	return 0;
}
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
	double m, n; cin >> m >> n;
	double ans = 0;
	for (double i = 1; i <= m; i++)
		ans += i * (pow(i / m, n) - pow((i - 1) / m, n));
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
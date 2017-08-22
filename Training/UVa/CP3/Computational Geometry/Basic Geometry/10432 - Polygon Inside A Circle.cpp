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
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double r, n;
	while (cin >> r >> n)
		cout << fixed << setprecision(3) << (r * r * n * sin((2 * PI) / n)) * 0.5 << endl;
	return 0;
}
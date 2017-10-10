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

const int oo = 1e9;
const double PI = acos(-1);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double a, b, v, A, s;
	while (cin >> a >> b >> v >> A >> s && a) {
		double vx = v * cos(A * PI / 180.0), vy = v * sin(A * PI / 180.0);
		double dx = vx * s * 0.5, dy = vy * s * 0.5;
		cout << ceil((dx + a * 0.5) / a) - 1 << " " << ceil((dy + b * 0.5) / b) - 1 << endl;
	}
	return 0;
}
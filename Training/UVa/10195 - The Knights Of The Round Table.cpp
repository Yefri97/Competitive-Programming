#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double a, b, c;
	while (cin >> a >> b >> c) {
		double s = (a + b + c) * 0.5;
		double ans = (s == 0) ? 0 : sqrt((s - a) * (s - b) * (s - c) / s);
		cout << "The radius of the round table is: " << fixed << setprecision(3) << ans << endl;
	}
	return 0;
}
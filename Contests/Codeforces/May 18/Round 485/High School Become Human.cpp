#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const double EPS = 1e-6;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, y;
	while (cin >> x >> y) {
		double a = y * log(x);
		double b = x * log(y);
		if (abs(a - b) < EPS)
			cout << "=" << endl;
		else if (a < b)
			cout << "<" << endl;
		else
			cout << ">" << endl;
	}
	return 0;
}

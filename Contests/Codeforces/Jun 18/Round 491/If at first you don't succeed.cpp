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
	int a, b, c, n; cin >> a >> b >> c >> n;
	int x = a + b - c;
	if (a >= c && b >= c && x < n)
		cout << n - x << endl;
	else
		cout << -1 << endl;
	return 0;
}

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
	int p1, p2, t1, t2; cin >> p1 >> p2 >> t1 >> t2;
	int x = max((3 * p1) / 10, p1 - p1 / 250 * t1);
	int y = max((3 * p2) / 10, p2 - p2 / 250 * t2);
	if (x > y)
		cout << "Misha" << endl;
	else if (x < y)
		cout << "Vasya" << endl;
	else
		cout << "Tie" << endl;
	return 0;
}

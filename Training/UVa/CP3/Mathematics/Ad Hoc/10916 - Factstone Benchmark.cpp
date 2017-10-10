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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int y;
	while (cin >> y && y) {
		int a = (1 << ((y - 1960) / 10 + 2)), b = 1;
		double acc = 0;
		while (acc + log2(b + 1) < a) acc += log2(b + 1), b++;
		cout << b << endl;
	}
	return 0;
}
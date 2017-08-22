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

bool solver(int a, int b) {
	int acc = a * 100 + b * 200;
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			if (2 * (i * 100 + j * 200) == acc)
				return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int a = 0, b = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		if (x == 100) a++;
		else b++;
	}
	bool ans = solver(a, b);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
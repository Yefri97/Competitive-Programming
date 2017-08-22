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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n + 1) {
		fori(j, 0, n - i) cout << "  ";
		fori(j, 0, i) cout << j << " ";
		cout << i;
		fori(j, 0, i) cout << " " << i - j - 1;
		cout << endl;
	}
	for (int i = n - 1; i >= 0; i--) {
		fori(j, 0, n - i) cout << "  ";
		fori(j, 0, i) cout << j << " ";
		cout << i;
		fori(j, 0, i) cout << " " << i - j - 1;
		cout << endl;
	}
	return 0;
}
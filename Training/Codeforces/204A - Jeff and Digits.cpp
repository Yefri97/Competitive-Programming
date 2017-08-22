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

const int INF = 1e9, MAXN = 1010;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	int cero = 0, five = 0;
	fori(i, 0, n) {
		cero += (A[i] == 0);
		five += (A[i] == 5);
	}
	if (cero) {
		if (five >= 9) {
			fori(i, 0, 9 * (five / 9))
				cout << 5;
			fori(i, 0, cero)
				cout << 0;
			cout << endl;
		} else {
			cout << 0 << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
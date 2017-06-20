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

const int INF = 1e9, MAXN = 110;

int A[MAXN];

bool solver(int n) {
	fori(i, 0, n)
		if (A[i] == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(k, 0, 2) {
		int p; cin >> p;
		fori(i, 0, p) {
			int x; cin >> x; x--;
			A[x] = 1;
		}
	}
	bool ans = solver(n);
	cout << (ans ? "I become the guy." : "Oh, my keyboard!") << endl;
	return 0;
}
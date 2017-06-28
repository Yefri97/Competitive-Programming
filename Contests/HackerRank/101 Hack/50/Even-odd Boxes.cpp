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

const int INF = 1e9, MAXN = 100010;
int A[MAXN];

int solver(int n) {
	ll acc = accumulate(A, A + n, 0LL);
	if (acc < (((ll)n + 1) / 2) * 2 + ((ll)n / 2)) return -1;
	int x = 0, y = 0, z = 0;
	fori(i, 0, n) {
		if (A[i] % 2 != i % 2) {
			if (A[i] == 1) y++;
			else z++;
			x++;
		}
	}
	if (x % 2) return -1;
	return y <= z ? x / 2 : y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		fori(i, 0, n)
			cin >> A[i];
		int result = solver(n);
		cout << result << endl;
	}
	return 0;
}
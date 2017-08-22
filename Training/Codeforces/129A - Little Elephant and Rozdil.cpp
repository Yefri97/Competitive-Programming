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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	int min_val = A[0], ans = 0;
	fori(i, 1, n) {
		if (A[i] < min_val) {
			min_val = A[i];
			ans = i;
		}
	}
	fori(i, 0, n) {
		if (i != ans && min_val == A[i])
			ans = -1;
	}
	if (ans == -1) {
		cout << "Still Rozdil" << endl;
	} else {
		cout << ans + 1 << endl;
	}
	return 0;
}
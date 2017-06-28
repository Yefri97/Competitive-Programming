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

const int INF = 1e9, MAXN = 60;
int A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	int m; cin >> m;
	fori(i, 0, m)
		cin >> B[i];
	int max_val = -1;
	fori(i, 0, n) {
		fori(j, 0, m) {
			if (B[j] % A[i] == 0)
				max_val = max(max_val, B[j] / A[i]);
		}
	}
	int ans = 0;
	fori(i, 0, n) {
		fori(j, 0, m) {
			if (B[j] % A[i] == 0)
				ans += (max_val == B[j] / A[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
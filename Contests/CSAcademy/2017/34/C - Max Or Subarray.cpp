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
	vi pos(30, -1);
	int pa = 0, pb = 0, ans = INF, value = 0;
	while (pa < n) {
		int x = A[pa];
		fori(i, 0, 31) {
			if (x & (1 << i)) {
				if (pos[i] != -1)
					A[pos[i]] ^= (1 << i);
				pos[i] = pa;
			}
		}
		while (pb < pa && A[pb] == 0) pb++;
		if ((value | x) > value) {
			value |= x;
			ans = pa - pb + 1;
		} else {
			ans = min(ans, pa - pb + 1);
		}
		pa++;
	}
	cout << ans << endl;
	return 0;
}
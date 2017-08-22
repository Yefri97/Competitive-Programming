#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 1000;

int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(A, -1, sizeof A);
	int n, k; cin >> n >> k;
	fori(i, 0, k) {
		int x; cin >> x; x--;
		A[x] = i;
	}
	int curr = 0, cnt = 0;
	fori(i, 0, n * k) {
		if (A[i] != -1) continue;
		A[i] = curr;
		cnt++;
		if (cnt == n - 1) curr++, cnt = 0;
	}
	vector<vi> ans(k);
	fori(i, 0, n * k)
		ans[A[i]].push_back(i);
	fori(i, 0, ans.size()) {
		fori(j, 0, ans[i].size())
			cout << ans[i][j] + 1 << " ";
		cout << endl;
	}
	return 0;
}
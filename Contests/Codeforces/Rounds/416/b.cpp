#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 10010;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		cin >> A[i];
	while (m--) {
		int l, r, x; cin >> l >> r >> x;
		int cnt = 0, val = A[x - 1];
		fori(i, l - 1, r)
			cnt += (A[i] < val);
		if (cnt == x - l)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
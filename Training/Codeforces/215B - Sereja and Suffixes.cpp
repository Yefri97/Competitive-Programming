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
int A[MAXN], ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		cin >> A[i];
	set<int> s;
	for (int i = n - 1; i >= 0; i--) {
		s.insert(A[i]);
		ans[i] = s.size();
	}
	while (m--) {
		int x; cin >> x; x--;
		cout << ans[x] << endl;
	}
	return 0;
}
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

const int INF = 1e9, MAXN = 10010;
int A[MAXN];

int n, m;

int solver(int x, int d) {
	int ans = 0;
	fori(i, 0, n * m) {
		if (abs(A[i] - x) % d != 0) return -1;
		ans += abs(A[i] - x) / d;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int d; cin >> n >> m >> d;
	fori(i, 0, n * m)
		cin >> A[i];
	sort(A, A + (n * m));
	int x = A[(n * m) / 2];
	int ans = solver(x, d);
	cout << ans << endl;
	return 0;
}
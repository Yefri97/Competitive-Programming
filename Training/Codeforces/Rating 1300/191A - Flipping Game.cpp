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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int acc = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		A[i] = (x ? -1 : 1);
		acc += x;
	}
	int sum = 0, ans = -1;
	fori(i, 0, n) {
		sum += A[i];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	cout << acc + ans << endl;
	return 0;
}
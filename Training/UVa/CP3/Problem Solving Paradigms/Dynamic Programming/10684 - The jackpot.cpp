// Max 1D Range Sum
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n != 0) {
		fori(i, 0, n)
			cin >> A[i];
		int sum = 0, ans = 0;
		fori(i, 0, n) {
			sum += A[i];
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		if (ans > 0) {
			cout << "The maximum winning streak is " << ans << "." << endl;
		} else {
			cout << "Losing streak." << endl;
		}
	}
	return 0;
}
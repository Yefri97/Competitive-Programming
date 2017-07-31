#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> ii;
typedef vector<ii> vii;

const int oo = 2e9 + 10, mxn = 1000010;

int n;
ll X[mxn], Y[mxn], taken[mxn], q[mxn];
ii A[mxn], B[mxn];

bool check(ll d) {
	int la = 0, ra = n - 1, lb = 0, rb = n - 1, cnt = 1;
	fori(i, 0, n) taken[i] = 0; taken[0] = 1;
	int h = 0, t = 0; q[t++] = 0;
	while (h != t) {
		int u = q[h++];
		while (la <= ra && A[la].first <= X[u] + Y[u] - d) {
			if (!taken[A[la].second]) {
				taken[A[la].second] = 1;
				q[t++] = A[la].second;
				cnt++;
			}
			la++;
		}
		while (lb <= rb && B[lb].first <= X[u] - Y[u] - d) {
			if (!taken[B[lb].second]) {
				taken[B[lb].second] = 1;
				q[t++] = B[lb].second;
				cnt++;
			}
			lb++;
		}
		while (la <= ra && A[ra].first >= X[u] + Y[u] + d) {
			if (!taken[A[ra].second]) {
				taken[A[ra].second] = 1;
				q[t++] = A[ra].second;
				cnt++;
			}
			ra--;
		}
		while (lb <= rb && B[rb].first >= X[u] - Y[u] + d) {
			if (!taken[B[rb].second]) {
				taken[B[rb].second] = 1;
				q[t++] = B[rb].second;
				cnt++;
			}
			rb--;
		}
	}
	return cnt == n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, n) {
			cin >> X[i] >> Y[i];
			A[i] = ii(X[i] + Y[i], i);
			B[i] = ii(X[i] - Y[i], i);
		}
		sort(A, A + n);
		sort(B, B + n);
		ll low = 0, high = oo;
		while (high - low > 1) {
			ll mid = (high + low) * 0.5;
			if (check(mid)) low = mid;
			else high = mid;
		}
		cout << low << endl;
	}
	return 0;
}
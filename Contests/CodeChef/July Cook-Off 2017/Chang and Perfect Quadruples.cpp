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

const int oo = 2e9, mxn = 1000010, kmod = 1e9 + 7;

ll A[mxn], mleft[mxn], mright[mxn], sumMax[mxn], sumMin[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];

	// MAX
	stack<int> a, b;
	a.push(-1); b.push(n);
	fori(i, 0, n) {
		while ((a.top() == -1 ? oo : A[a.top()]) < A[i]) a.pop();
		mleft[i] = a.top();
		a.push(i);
		while ((b.top() == n ? oo : A[b.top()]) <= A[n - i - 1]) b.pop();
		mright[n - i - 1] = b.top();
		b.push(n - i - 1);
	}
	fori(i, 0, n) {
		ll len = (ll)i - mleft[i];
		sumMax[i] += len * A[i];
		sumMax[mright[i]] -= len * A[i];
	}
	fori(i, 1, n)
		sumMax[i] = (sumMax[i] + sumMax[i - 1]) % kmod;
	// MIN
	while (!a.empty()) a.pop();
	while (!b.empty()) b.pop();
	a.push(-1); b.push(n);
	fori(i, 0, n) {
		while ((a.top() == -1 ? -oo : A[a.top()]) > A[i]) a.pop();
		mleft[i] = a.top();
		a.push(i);
		while ((b.top() == n ? -oo : A[b.top()]) >= A[n - i - 1]) b.pop();
		mright[n - i - 1] = b.top();
		b.push(n - i - 1);
	}
	fori(i, 0, n) {
		ll len = mright[i] - (ll)i;
		sumMin[i] += len * A[i];
		sumMin[mleft[i]] -= len * A[i];
	}
	fori(i, 1, n)
		sumMin[n - i - 1] = (sumMin[n - i - 1] + sumMin[n - i]) % kmod;
	// SUM
	fori(i, 1, n)
		sumMin[n - i - 1] = (sumMin[n - i - 1] + sumMin[n - i]) % kmod;
	// ANS
	ll ans = 0;
	fori(i, 1, n)
		ans = (ans + sumMax[i-1] * sumMin[i]) % kmod;
	cout << ans << endl;
	return 0;
}
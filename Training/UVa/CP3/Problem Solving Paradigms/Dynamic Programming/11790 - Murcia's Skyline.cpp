// Longest Increasing Subsequence (LIS)
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

const int INF = 1e9, MAXN = 1000010;
int A[MAXN], B[MAXN], n;
int L[MAXN], W[MAXN];

int solver() {
	vi lis(B, B + n);
	fori(i, 0, n)
		fori(j, 0, i)
			if (A[j] < A[i])
				lis[i] = max(lis[i], lis[j] + B[i]);
	int ans = 0;
	fori(i, 0, n)
		ans = max(ans, lis[i]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		cin >> n;
		fori(i, 0, n)
			cin >> A[i];
		fori(i, 0, n)
			cin >> B[i];
		int inc = solver();
		fori(i, 0, n / 2)
			swap(A[i], A[n - i - 1]);
		fori(i, 0, n / 2)
			swap(B[i], B[n - i - 1]);
		int dec = solver();
		cout << "Case " << ++cs << ". ";
		if (inc >= dec) {
			cout << "Increasing (" << inc << "). Decreasing (" << dec << ")." << endl;
		} else {
			cout << "Decreasing (" << dec << "). Increasing (" << inc << ")." << endl;
		}
	}
	return 0;
}
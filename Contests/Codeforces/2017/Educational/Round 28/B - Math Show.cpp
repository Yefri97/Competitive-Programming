#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 50;

int A[mxn];

int calc(int n, int k, int m) {
	int ans = 0;
	priority_queue< int, vector<int>, greater<int> > pq;
	fori(i, 0, k)
		fori(j, 0, n)
			pq.push(A[i]);
	while (!pq.empty() && pq.top() <= m) {
		int t = pq.top(); pq.pop();
		m -= t;
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k, m;
	while (cin >> n >> k >> m) {
		fori(i, 0, k)
			cin >> A[i];
		int ans = 0, acc = accumulate(A, A + k, 0);
		fori(i, 0, n + 1) {
			if (i * acc > m) break;
			ans = max(ans, i * (k + 1) + calc(n - i, k, m - i * acc));
		}
		cout << ans << endl;
	}
	return 0;
}
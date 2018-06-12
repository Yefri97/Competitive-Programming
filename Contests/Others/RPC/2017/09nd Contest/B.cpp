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

const int oo = 1e9, mxn = 500010;

int A[mxn], freq[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		fori(i, 0, n - 2) {
			int x; cin >> x; x--;
			freq[x]++;
			A[i] = x;
		}
		priority_queue<int, vector<int>, greater<int> > pq;
		fori(i, 0, n)
			if (freq[i] == 0)
				pq.push(i);
		vii ans;
		fori(i, 0, n - 2) {
			int u = A[i], v = pq.top(); pq.pop();
			freq[u]--;
			if (freq[u] == 0)
				pq.push(u);
			if (u > v)
				swap(u, v);
			ans.push_back(ii(u, v));
		}
		int u = pq.top(); pq.pop();
		int v = pq.top(); pq.pop();
		ans.push_back(ii(u, v));
		sort(ans.begin(), ans.end());
		fori(i, 0, ans.size())
			cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}
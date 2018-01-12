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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, T; cin >> n >> T;
	vector< vii > v(n);
	fori(i, 0, n) {
		int a, b; cin >> a >> b; a--;
		v[a].push_back(ii(b, i));
	}

	int sum = 0, ans = 0;
	priority_queue<ii> pq;

	for (int i = n; i > 0 && !ans; i--) {
		for (auto x : v[i - 1]) {
			pq.push(x);
			sum += x.first;
			if (pq.size() > i) {
				sum -= pq.top().first;
				pq.pop();
			}
		}
		if (pq.size() == i) {
			if (sum > T) {
				sum -= pq.top().first;
				pq.pop();
			} else {
				ans = i;
			}
		}
	}
	
	cout << ans << endl;
	cout << ans << endl;
	while (!pq.empty()) {
		ii x = pq.top(); pq.pop();
		cout << x.second + 1 << " ";
	}
	cout << endl;
	return 0;
}
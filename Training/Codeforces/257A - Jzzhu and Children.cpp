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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	deque<ii> dq;
	int n, m; cin >> n >> m;
	fori(i, 0, n) {
		int x; cin >> x;
		dq.push_back(ii(x, i));
	}
	while (dq.size() > 1) {
		ii front = dq.front(); dq.pop_front();
		int x = front.first, idx = front.second;
		if (x > m) dq.push_back(ii(x - m, idx));
	}
	cout << dq.front().second + 1 << endl;
	return 0;
}
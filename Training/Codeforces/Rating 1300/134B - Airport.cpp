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
	int n, m; cin >> n >> m;
	priority_queue<int> A, B;
	fori(i, 0, m) {
		int x; cin >> x;
		A.push(x);
		B.push(-x);
	}
	int max_val = 0;
	fori(i, 0, n) {
		int x = A.top(); A.pop();
		max_val += x;
		if (x > 1) A.push(x - 1);
	}
	int min_val = 0;
	fori(i, 0, n) {
		int x = B.top(); B.pop();
		x = -x;
		min_val += x;
		if (x > 1) B.push(-(x - 1));
	}
	cout << max_val << " " << min_val << endl;
	return 0;
}
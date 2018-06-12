#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	priority_queue<ii> pq_min, pq_max;
	fori(i, 0, n) {
		int c; cin >> c;
		pq_min.push(ii(-c, i));
	}
	string s; cin >> s;
	fori(i, 0, 2 * n) {
		if (s[i] == '0') {
			ii x = pq_min.top(); pq_min.pop();
			int c = -x.first, r = x.second;
			cout << r + 1 << " ";
			pq_max.push(ii(c, r));
		} else {
			ii x = pq_max.top(); pq_max.pop();
			cout << x.second + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}

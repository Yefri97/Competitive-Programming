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

vi q[MAXN];

bool smaller(int x, int y) {
	cout << "Q " << x << " " << y;
	int ans; cin >> ans;
	return x == ans;
}

int solver(int l, int r) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	int a = solver(l, mid);
	int b = solver(mid + 1, r);

	if (smaller(a, b)) {
		q[a].push_back(b);
		return a;
	} else {
		q[b].push_back(a);
		return b;
	}
}

int main() {
	int n; cin >> n;
	int first_min = solver(1, n);

	int second_min = q[first_min][0];
	fori(i, 1, q[first_min].size()) {
		if (smaller(q[first_min][i], second_min))
			second_min = q[first_min][i];
	}
	cout << "A " << second_min;
	return 0;
}
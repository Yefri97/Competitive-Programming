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
	int n, k; cin >> n >> k;
	map<int, int> mapper;
	fori(i, 0, n) {
		int x; cin >> x;
		mapper[x - i * k]++;
	}
	int ans = 0;
	for (ii m : mapper)
		ans = max(ans, m.second);
	cout << n - ans << endl;
	return 0;
}

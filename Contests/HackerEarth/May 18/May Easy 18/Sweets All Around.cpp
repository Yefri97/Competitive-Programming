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
	map<int, int> m;
	int n; cin >> n;
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		m[a]++;
		m[b + 1]--;
	}
	int val = 0, max_val = 0, candies = 0;
	for (auto c : m) {
		val += c.second;
		if (val > max_val) {
			max_val = val;
			candies = c.first;
		}
	}
	cout << candies << " " << max_val << endl;
	return 0;
}

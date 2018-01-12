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
	int n, x; cin >> n >> x;
	if (n == 2 && x == 0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		set<int> st;
		int xacc = 0;
		fori(i, 0, n - 1) {
			st.insert(i);
			xacc ^= i;
		}
		int m = x ^ xacc;
		if (st.find(m) != st.end()) {
			if (m == 0) {
				st.erase(1);
				st.insert(1 << 17);
				st.insert((1 << 17) | 1);
			} else {
				st.erase(0);
				st.insert(1 << 17);
				st.insert((1 << 17) | m);
			}
		} else {
			st.insert(m);
		}
		for (auto c : st)
			cout << c << " ";
		cout << endl;
	}
	return 0;
}
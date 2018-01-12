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
	stack<int> st;
	int n, cnt = 1, ans = 0; cin >> n; n *= 2;
	while (n--) {
		string cmd; cin >> cmd;
		if (cmd == "add") {
			int x; cin >> x;
			st.push(x);
		} else {
			if (!st.empty()) {
				int x = st.top(); st.pop();
				if (x != cnt) {
					while (!st.empty()) st.pop();
					ans++;
				}
			}
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}